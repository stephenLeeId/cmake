public class Test
{
    public static void main(String argv[])
    {
		  System.out.println("main.....hello world  ");



      int faceNum = 2;
      String Base64CutImage = "hello"; 
      byte[] byteCutImage = {1, 2, 3};
      FaceInfo A = new FaceInfo(faceNum, Base64CutImage, byteCutImage );
      FaceInfo B = A;
      FaceInfo C = A.clone();
      A.faceNum = 3;
      A.Base64CutImage = "zhngli";
      A.byteCutImage[0] = 10;
      B.testPrintf();
      C.testPrintf();


    }
}

