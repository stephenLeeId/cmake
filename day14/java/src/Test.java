
import com.renren.face.*;
public class Test
{
    public static void main(String argv[])
    {
		  System.out.println("main.....hello world  my name is feili");


      float ret = FaceInterface.add(1.0f, 3.4f);

      System.out.print("FaceInterface.add(1.0f, 3.4f)=");System.out.println(ret);

/*
      String path = "D:/hello/a.txt";
      String retPath = FaceInterface.SetString(path);
      System.out.println(retPath);

      byte mByte = 'b';

      byte retmByte = FaceInterface.SetByte(mByte);
      System.out.println(retmByte);

      //byte[] mByteArray = {'a', 'b', 'c', 'd'};
      byte[] mByteArray = new byte[10];
      mByteArray[0] = 'a';
      mByteArray[1] = 'b';
      mByteArray[2] = 'c';
      mByteArray[3] = 'd';
      for(int i = 0; i < 10; i ++)
      {
          //mByteArray[i] = 'a';
      }

      byte[] retmByteArray = FaceInterface.SetByteArray(mByteArray);
      System.out.println("mByteArray =");
      System.out.println(mByteArray[0]);System.out.println(mByteArray[1]);System.out.println(mByteArray[2]);System.out.println(mByteArray[3]);

      System.out.println("retmByteArray =");
      System.out.println("retmByteArray.size =" + retmByteArray.length);
      System.out.println(retmByteArray[0]);System.out.println(retmByteArray[1]);System.out.println(retmByteArray[2]);System.out.println(retmByteArray[3]);
      



      int mInt = 999999;
      int retmInt = FaceInterface.SetInt(mInt);
      System.out.println("retmInt =" + retmInt);


      int[] mIntArray = {1001, 1002, 1003, 1004};


      int[] retmIntArray = FaceInterface.SetIntArray(mIntArray);

      System.out.println("mIntArray =");
      System.out.println(mIntArray[0]);System.out.println(mIntArray[1]);System.out.println(mIntArray[2]);System.out.println(mIntArray[3]);

      System.out.println("retmIntArray =");
      System.out.println("retmIntArray.size =" + retmIntArray.length);
      System.out.println(retmIntArray[0]);System.out.println(retmIntArray[1]);System.out.println(retmIntArray[2]);System.out.println(retmIntArray[3]);
      


      long mLong = 999999;
      long retmLong = FaceInterface.SetLong(mLong);
      System.out.println("retmLong =" + retmLong);


      long[] mLongArray = {2001, 2002, 2003, 2004};


      long[] retmLongArray = FaceInterface.SetLongArray(mLongArray);

      System.out.println("mLongArray =");
      System.out.println(mLongArray[0]);System.out.println(mLongArray[1]);System.out.println(mLongArray[2]);System.out.println(mLongArray[3]);

      System.out.println("retmLongArray =");
      System.out.println("retmLongArray.size =" + retmLongArray.length);
      System.out.println(retmLongArray[0]);System.out.println(retmLongArray[1]);System.out.println(retmLongArray[2]);System.out.println(retmLongArray[3]);
      

      float[] mFloatArray = {2001.1f, 2002.4f, 2003.9f, 2004.6f};


      float[] retmFloatArray = FaceInterface.SetFloatArray(mFloatArray);

      System.out.println("SetFloat =" + FaceInterface.SetFloat(1111.0234f));
      System.out.println("mFloatArray =");
      System.out.println(mFloatArray[0]);System.out.println(mFloatArray[1]);System.out.println(mFloatArray[2]);System.out.println(mFloatArray[3]);

      System.out.println("retmFloatArray =");
      System.out.println("retmFloatArray.size =" + retmFloatArray.length);
      System.out.println(retmFloatArray[0]);System.out.println(retmFloatArray[1]);System.out.println(retmFloatArray[2]);System.out.println(retmFloatArray[3]);
      

      double[] mDoubleArray = {2001.19, 2002.46, 2003.98, 2004.69};


      double[] retmDoubleArray = FaceInterface.SetDoubleArray(mDoubleArray);
      System.out.println("SetDouble =" + FaceInterface.SetDouble(2222.333));
      System.out.println("mDoubleArray =");
      System.out.println(mDoubleArray[0]);System.out.println(mDoubleArray[1]);System.out.println(mDoubleArray[2]);System.out.println(mDoubleArray[3]);

      System.out.println("retmDoubleArray =");
      System.out.println("retmDoubleArray.size =" + retmDoubleArray.length);
      System.out.println(retmDoubleArray[0]);System.out.println(retmDoubleArray[1]);System.out.println(retmDoubleArray[2]);System.out.println(retmDoubleArray[3]);
      */

       int[][] i2arr = FaceInterface.getInt2DArray(3);

       int rowNum = i2arr.length;
        int colNum=0;
        if(rowNum>0)
        {
            colNum = i2arr[0].length;
        }
        System.out.println("rowNum = " + rowNum + "colsNums = " + colNum );

         for (int i = 0; i < rowNum; i++) {

             for (int j = 0; j < colNum; j++) {

                  System.out.print(" " + i2arr[i][j]);

             }

             System.out.println();

         }

        FaceInfo mFaceInfo = FaceInterface.getFaceInfo();

        System.out.println("faceNum =" + mFaceInfo.faceNum);
        System.out.println("Base64CutImage =" + mFaceInfo.Base64CutImage);
        System.out.println("byteCutImage =" + mFaceInfo.byteCutImage[0]);


        FaceInfo[] mFaceInfoArray = FaceInterface.getFaceInfoArray();


        for(int i = 0; i < mFaceInfoArray.length; i ++)
        {
            System.out.println(i + "faceNum =" + mFaceInfoArray[i].faceNum);
            System.out.println(i + "Base64CutImage =" + mFaceInfoArray[i].Base64CutImage);
            System.out.println(i + "byteCutImage =" + mFaceInfoArray[i].byteCutImage);
        }

        byte[] t_setByteA = {1, 2, 3, 4};
        FaceInfo t_faceInfo = new FaceInfo(10, "setHelloWorld", t_setByteA);


        FaceInterface.setFaceInfo(t_faceInfo);

        byte[]  mm_byte = t_faceInfo.getByteCutImage();

        System.out.println(" t_faceInfo " + t_faceInfo.byteCutImage[0] + " " + t_faceInfo.byteCutImage[1] + " " + t_faceInfo.byteCutImage[2] 
        + " " + t_faceInfo.byteCutImage[3]);


        


    }
}

