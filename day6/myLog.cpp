
//#include "Config.h"
#include "myLog.h"
#include <vector>
#include <string>
#include <fstream>  


#ifdef WIN32
#include <io.h>
#include <direct.h>

#else

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <malloc.h>
#include <dirent.h>


#endif

/*
#if OS_S==OS_Linux
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <malloc.h>
#include <dirent.h>


#elif OS_S== OS_iOS
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#elif OS_S == OS_Windows
#include <io.h>
#include <direct.h>
#endif
*/


#if ANDROID
std::string dumpRoot = "/storage/emulated/0/cpplog"; //
#else

std::string dumpRoot = "./cpplog"; //
#endif

std::mutex mux;
static FILE * fp = NULL;
int MaxLenChar = 1024; // ,  1024 * 1024 * 5
int MaxLogNum = 4;

static int com(const void *a, const void *b)
{
    long long * p1, *p2;
    p1 = (long long *)a;  //
    p2 = (long long *)b;  //

    return *p1 > *p2 ? 1 : -1;
}


// 
void GetName(std::vector<std::string> &vPath, std::vector<std::string> &vName)
{
	if (vPath.size() <= 0)
	{
		printf("vPath.size <= 0");
		return;
	}
	for (int i = 0; i < vPath.size(); i++)
	{
		std::string path = vPath[i];

		int pointDot = path.find_last_of('.');

#ifdef WIN32
		int pointN = path.find_last_of('\\');
#else
		int pointN = path.find_last_of('/');
#endif

		std::string name = path.substr(pointN + 1, pointDot - pointN - 1);
		vName.push_back(name);

	}

}



static int removeOldFile(std::string &rootPath)
{

    std::vector<std::string> files;

    std::vector<long long> filesNum;

	LOGEM("removeOldFile ");
    getFiles(rootPath, files);

	LOGEM("rootPath = %s files.size = %d \n", rootPath.c_str(), files.size());
    if (files.size() > MaxLogNum)
    {
        for (int i = 0; i < files.size(); i++)
        {
            int pos0 = files[i].find("LOG_");

            std::string cut = files[i].substr(pos0 + 4, files[i].size());

            char* endptr = NULL;
            long long num = std::strtoll(cut.c_str(), &endptr, 10);

            LOGEM("cut = %s num = %lld \n", cut.c_str(), num);

            filesNum.push_back(num);

        }
        qsort(&filesNum.data()[0], filesNum.size(), sizeof(long long), com);

        // 
        LOGEM(" delete num = %d   \n", filesNum.size() - 5);
        long long deleteNum = filesNum.size() - MaxLogNum;

        for (int i = 0; i < deleteNum; i++)
        {
            std::string logPath = rootPath + std::string("/LOG_") + std::to_string(filesNum[i]);
            LOGEM("删除文件= %s   \n", logPath.c_str());
            remove(logPath.c_str());
        }
    }

    return 0;
}


int dump_init_temp() {

#undef FUNC_CODE
#define FUNC_CODE 0x01

	//create dump folder
#ifdef WIN32
	if (_access(dumpRoot.c_str(), 00) != 0) {
		_mkdir(dumpRoot.c_str());
#else
	if (access(dumpRoot.c_str(), R_OK|W_OK) != 0) 
	{
		mkdir(dumpRoot.c_str(), S_IRWXU);
#endif
	}

	return 0;
	}

int LOGINIT()
{

	dump_init_temp();

    removeOldFile(dumpRoot);
	
    long long currentMs = getCurrentMs();
    char currentMsStr[20];

    sprintf(currentMsStr,"%lld", currentMs);

    std::string logPath = dumpRoot + "/LOG_" + currentMsStr;

	fp = NULL;
    fp = fopen(logPath.c_str(), "w+");
	if (fp == NULL)
	{
		return -1;
	}
	return 0;
}
int LOGSetMaxSpace(int mSize)
{
	MaxLenChar = mSize;
	return 0;
}

int logWrite(char * s)
{
	if (fp)
	{
		mux.lock();
		fprintf(fp, "%s", s);
		fflush(fp);
		int len = ftell(fp);
		mux.unlock();
		if (len > MaxLenChar)
		{
			LOGEnd();
			LOGINIT();
			return 0;
		}
		
	}

	return 0;
}

int LOGEnd()
{
	if (fp)
	{
		fflush(fp);
		fclose(fp);
		fp = 0;
	}
	return 0;
}

std::string getCurrentSystemTime()
{
	auto time_now = std::chrono::system_clock::now();
	auto tt = std::chrono::system_clock::to_time_t(time_now);
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());
	auto duration_in_s = std::chrono::duration_cast<std::chrono::seconds>(time_now.time_since_epoch());
	int theMs = duration_in_ms.count() - duration_in_s.count() * 1000;
	struct tm* ptm = localtime(&tt);


	char date[60] = { 0 };
	sprintf(date, "%d-%02d-%02d-%02d.%02d.%02d.%03d%",
		(int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday,
		(int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec, theMs);
	return std::string(date);
}
long long getCurrentMs()
{
	auto time_now = std::chrono::system_clock::now();
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());

	return duration_in_ms.count();
}
std::string GetLastName(const char * fileName)
{
	char temp[256] = { 0 };
	memcpy(temp, fileName, strlen(fileName) + 1);

	std::string sName = temp;

#ifdef WIN32
	int startP = sName.find_last_of("\\");
	if (startP == -1)
	{
		startP = 0;
	}
	std::string theLastName = sName.substr(startP + 1, sName.size() - startP);

#else
	int startP = sName.find_last_of("/");
	if (startP == -1)
	{
		startP = 0;
	}
	std::string theLastName = sName.substr(startP + 1, sName.size() - startP);

#endif
	return theLastName;
}


static int rm_dir(std::string dir_full_path)
{ 

#ifdef WIN32
    
#else
	DIR* dirp = opendir(dir_full_path.c_str());
	if (!dirp)
	{
		return -1;
	}
	struct dirent *dir;
	struct stat st;
	while ((dir = readdir(dirp)) != NULL)
	{
		if (strcmp(dir->d_name, ".") == 0
			|| strcmp(dir->d_name, "..") == 0)
		{
			continue;
		}
		std::string sub_path = dir_full_path + '/' + dir->d_name;
		if (lstat(sub_path.c_str(), &st) == -1)
		{
			printf("rm_dir:lstat %s", sub_path.c_str());
			continue;
		}
		if (S_ISDIR(st.st_mode))
		{
			if (rm_dir(sub_path) == -1) // 如果是目录文件，递归删除
			{
				closedir(dirp);
				return -1;
			}
			rmdir(sub_path.c_str());
		}
		else if (S_ISREG(st.st_mode))
		{
			unlink(sub_path.c_str());     // 如果是普通文件，则unlink
		}
		else
		{
			printf("rm_dir:st_mode %s", sub_path.c_str());
			continue;
		}
	}
	if (rmdir(dir_full_path.c_str()) == -1)//delete dir itself.
	{
		closedir(dirp);
		return -1;
	}
	closedir(dirp);

#endif
    return 0;
}

int rm(std::string file_name)
{

#ifdef WIN32


#else

    std::string file_path = file_name;
    struct stat st;    
    if(lstat(file_path.c_str(),&st) == -1)
    {
        return -1;
    }
    if(S_ISREG(st.st_mode))
    {
        if(unlink(file_path.c_str()) == -1)
        {
            return -1;
        }    
    }
    else if(S_ISDIR(st.st_mode))
    {
        if(file_name == "." || file_name == "..")
        {
            return -1;
        }    
        if(rm_dir(file_path) == -1)//delete all the files in dir.
        {
            return -1;
        }
    }
#endif
    return 0;
}



void getFiles(std::string cate_dir, std::vector<std::string> &files)
{

 

#ifdef WIN32
	
	intptr_t   hFile = 0;

	struct _finddata_t fileinfo;//    
	std::string p;
	if ((hFile = _findfirst(p.assign(cate_dir).append("\\*").c_str(), &fileinfo)) != -1)  //  
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))  //  
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)  //  
				{
					files.push_back(p.assign(cate_dir).append("\\").append(fileinfo.name));
					getFiles(p.assign(cate_dir).append("\\").append(fileinfo.name), files);

				}
			}
			else //   
			{


				files.push_back(p.assign(cate_dir).append("\\").append(fileinfo.name));
			}

		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile); //  
	}
#else


	DIR *dir;
	struct dirent *ptr;
	char base[1000];
 
	if ((dir=opendir(cate_dir.c_str())) == NULL)
        {
		perror("Open dir error...");
                exit(1);
        }
 
	while ((ptr=readdir(dir)) != NULL)
	{
		if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
		{
 			continue;
		}	       
		else if(ptr->d_type == 8)    ///file
		{
			//printf("d_name:%s/%s\n",basePath,ptr->d_name);
			files.push_back(ptr->d_name);
		}
		else if(ptr->d_type == 10)    ///link file
		{
			//printf("d_name:%s/%s\n",basePath,ptr->d_name);
			continue;
		}
		else if(ptr->d_type == 4)    ///dir
		{
			files.push_back(ptr->d_name);
			/*
		        memset(base,'\0',sizeof(base));
		        strcpy(base,basePath);
		        strcat(base,"/");
		        strcat(base,ptr->d_nSame);
		        readFileList(base);
			*/
		}
	}
	closedir(dir);

#endif
 
	//排序，按从小到大排序
	 //std::sort(files.begin(), files.end())

}

