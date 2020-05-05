
public class FaceInfo implements Cloneable {
	public int faceNum; public String Base64CutImage; public byte[] byteCutImage;
	public FaceInfo clone() {
		FaceInfo clone = null;         
		try { clone = (FaceInfo)super.clone();    
		clone.byteCutImage = this.byteCutImage.clone();
		}
		catch (CloneNotSupportedException e) {
			throw new RuntimeException(e); // won't happen        
		}        
		return clone;
	}
	// 下面三个函数为了让测试cpp 调用java的函数
	public int getfaceNum()
	{
		return faceNum;
	}
	public String getBase64CutImage()
	{
		return Base64CutImage;
	}
	public byte[] getByteCutImage()
	{
		return byteCutImage;
	}
	public FaceInfo(int faceNum_, String Base64CutImage_, byte[] byteCutImage_){ 
		this.faceNum = faceNum_;   this.Base64CutImage = Base64CutImage_; this.byteCutImage = byteCutImage_;
	}
	public testPrintf(){ 
		System.out.print("faceNum=");System.out.println(faceNum);
		System.out.print("Base64CutImage =");System.out.println(Base64CutImage );
		System.out.print("byteCutImage =");System.out.println(byteCutImage );
	}
}
