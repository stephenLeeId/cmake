package com.renren.face;
public class FaceInfo implements Cloneable {

    public int faceNum;
	
	public String Base64CutImage;
	
	public byte[] byteCutImage;

    	/**
	 * 创建副本
	 */

	public void setFaceNum(int num)
	{
		this.faceNum = num;
		System.out.println("c to java setFaceNum  ......." + num);
	}
	public FaceInfo clone() {
	 
        FaceInfo clone = null; 
        try{ 
            clone = (FaceInfo) super.clone(); 
            //clone.Base64CutImage = this.Base64CutImage.clone();
            clone.byteCutImage = this.byteCutImage.clone();
 
        }catch(CloneNotSupportedException e){ 
            throw new RuntimeException(e); // won't happen 
        }
        return clone;
	}
	
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
	public FaceInfo(int faceNum_, String Base64CutImage_, byte[] byteCutImage_)
	{
		this.faceNum = faceNum_;
		this.Base64CutImage = Base64CutImage_;
		this.byteCutImage = byteCutImage_;
	}
	public void testPrintf(){ 
		System.out.print("faceNum=");System.out.println(faceNum);
		System.out.print("Base64CutImage =");System.out.println(Base64CutImage );
		System.out.print("byteCutImage =");System.out.println(byteCutImage );
	}
}
