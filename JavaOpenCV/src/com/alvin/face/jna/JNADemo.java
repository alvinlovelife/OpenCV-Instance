package com.alvin.face.jna;

import com.sun.jna.Library;
import com.sun.jna.Native;

/**
 * PROJECT_NAME�� JavaOpenCV
 * USER�� Alvin
 * DATE�� 2016/10/31
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
     *  ��ȡͼƬ�ĻҶȻ�����ͼs
     *  inPath������ͼƬ·��
     *  outPath�����ͼƬ·���������ļ�����������c:\\����
     */
    public static int grayface(String inPath,String outPath){
        return CLibrary.INSTANCE.grayface(inPath, outPath);
    }

    /**
     *  ʶ��ͼƬ�е��������ӿ�
     *  inPath������ͼƬ·��
     *  outPath�����ͼƬ·��
     */
    public static void rectface(String inPath,String outPath){
        CLibrary.INSTANCE.rectface(inPath, outPath);
    }

    public static void main(String[] args) {
        JNADemo.grayface("C:\\Users\\Administrator\\Desktop\\1.png", "C:\\Users\\Administrator\\Desktop\\");
        JNADemo.rectface("C:\\Users\\Administrator\\Desktop\\1.png", "C:\\Users\\Administrator\\Desktop\\tect1.png");
    }
}
