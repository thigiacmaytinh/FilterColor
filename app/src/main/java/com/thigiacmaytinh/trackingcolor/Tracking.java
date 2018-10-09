package com.thigiacmaytinh.trackingcolor;

import android.util.Log;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import static org.opencv.core.Core.bitwise_not;
import static org.opencv.core.Core.minMaxLoc;
import static org.opencv.core.Core.normalize;
import static org.opencv.imgproc.Imgproc.GaussianBlur;
import static org.opencv.imgproc.Imgproc.adaptiveThreshold;
import static org.opencv.imgproc.Imgproc.distanceTransform;
import static org.opencv.imgproc.Imgproc.drawContours;
import static org.opencv.imgproc.Imgproc.findContours;
import static org.opencv.imgproc.Imgproc.morphologyEx;
import static org.opencv.imgproc.Imgproc.threshold;

/**
 * Created by i5 on 12/30/2015.
 */
public class Tracking {
    static Scalar lower,higher;
    static Mat imgColor = new Mat();
    static Mat imgRemoveNoise = new Mat();

    static Mat DetectColor(Mat rgbImg)
    {
        Mat imgHSV = new Mat();
        Imgproc.cvtColor(rgbImg, imgHSV, Imgproc.COLOR_BGR2HSV);

        lower = new Scalar(Common.hMin, Common.sMin,Common.vMin);
        higher = new Scalar(Common.hMax, Common.sMax,Common.vMax);


        Core.inRange(imgHSV, lower, higher, imgColor);
        Mat kernel = Mat.ones(new Size(3, 3), CvType.CV_8U);
        morphologyEx(imgColor, imgRemoveNoise, Imgproc.MORPH_OPEN, kernel, new Point(-1, -1), 2);


        Mat imgResult = new Mat();
        Imgproc.cvtColor(imgRemoveNoise, imgResult, Imgproc.COLOR_GRAY2BGR);

//        Imgproc.Moments oMoments = moments(imgRemoveNoise);
//        double dM01 = oMoments.m01;
//        double dM10 = oMoments.m10;
//        double dArea = oMoments.m00;
//
//        // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
//        if (dArea > 10000)
//        {
//            //calculate the position of the ball
//            int posX = dM10 / dArea;
//            int posY = dM01 / dArea;
//
//            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
//            {
//                //Draw a red line from the previous point to the current point
//                Imgproc.line(imgResult, new Point(posX, posY), new Point(iLastX, iLastY), new Scalar(0, 0, 255), 2);
//                //Log.d(Common.d, text, "(%d, %d)", posX, posY);
//                Imgproc.putText(imgResult, text, new Point(30, 30), Core.FONT_HERSHEY_SIMPLEX, 0.5, new Scalar(0, 0, 255));
//            }
//
//            iLastX = posX;
//            iLastY = posY;
//        }


        return imgResult;
    }



}
