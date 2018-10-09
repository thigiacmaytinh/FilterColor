package com.thigiacmaytinh.trackingcolor;

import android.content.Context;
import android.hardware.Camera;
import android.util.AttributeSet;
import android.util.Log;

import org.opencv.android.JavaCameraView;
import android.hardware.Camera.Size;

import java.io.FileOutputStream;
import java.util.List;

/**
 * Created by i5 on 1/7/2016.
 */
public class CameraView  extends JavaCameraView {

    boolean isFlashLightON = false;
//    public CameraView(Context context, int cameraId) {
//        super(context, cameraId);
//    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void setupCameraFlashLight() {
        Camera camera = mCamera;
        if (camera != null)
        {
            Camera.Parameters params = camera.getParameters();

            if (params != null) {
                if (isFlashLightON) {
                    isFlashLightON = false;
                    params.setFlashMode(Camera.Parameters.FLASH_MODE_OFF);
                    camera.setParameters(params);
                    camera.startPreview();
                } else {
                    isFlashLightON = true;
                    params.setFlashMode(Camera.Parameters.FLASH_MODE_TORCH);
                    camera.setParameters(params);
                    camera.startPreview();

                }
            }
            mCamera.getParameters();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void setEffect(String effect)
    {
        if(mCamera != null) {
            mCamera.getParameters();
            Camera.Parameters params = mCamera.getParameters();
            params.setFlashMode(effect);
            mCamera.setParameters(params);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public CameraView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public List<String> getEffectList() {
        return mCamera.getParameters().getSupportedColorEffects();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    public boolean isEffectSupported() {
        return (mCamera.getParameters().getColorEffect() != null);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public String getEffect() {
        return mCamera.getParameters().getColorEffect();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public List<Size> getResolutionList() {
        return mCamera.getParameters().getSupportedPreviewSizes();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void setResolution(Size resolution) {
        disconnectCamera();
        mMaxHeight = resolution.height;
        mMaxWidth = resolution.width;
        connectCamera(getWidth(), getHeight());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public Size getResolution() {
        return mCamera.getParameters().getPreviewSize();
    }


}
