package com.alvin.face.jna;

import com.sun.jna.Library;
import com.sun.jna.Native;

/**
 * PROJECT_NAME： JavaOpenCV
 * USER： Alvin
 * DATE： 2016/10/31
 * TIME: 14:47
 */
public class JNADemo {
    public interface CLibrary extends Library{
        CLibrary INSTANCE = (CLibrary)
                Native.loadLibrary(("/OpenCVInstance.dll"),
                        CLibrary.class);

        int grayface(String inPath, String outPath);
        void rectface(String url, String url2);
    }

    /**
     *  获取图片的灰度化人脸图s
     *  inPath：输入图片路径
     *  outPath：输出图片路径（不含文件名，例：“c:\\”）
     */
    public static int grayface(String inPath,String outPath){
        return CLibrary.INSTANCE.grayface(inPath, outPath);
    }

    /**
     *  识别图片中的人脸并加框
     *  inPath：输入图片路径
     *  outPath：输出图片路径
     */
    public static void rectface(String inPath,String outPath){
        CLibrary.INSTANCE.rectface(inPath, outPath);
    }

    public static void main(String[] args) {
        JNADemo.grayface("C:\\Users\\Administrator\\Desktop\\1.png", "C:\\Users\\Administrator\\Desktop\\");
        JNADemo.rectface("C:\\Users\\Administrator\\Desktop\\1.png", "C:\\Users\\Administrator\\Desktop\\tect1.png");
    }
}
