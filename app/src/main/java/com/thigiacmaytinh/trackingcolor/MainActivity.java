package com.thigiacmaytinh.trackingcolor;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.Point;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.Display;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.widget.CheckBox;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RelativeLayout;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.android.Utils;
import org.opencv.core.CvType;
import org.opencv.core.Mat;

public class MainActivity extends Activity implements CvCameraViewListener2, View.OnTouchListener{

    CameraView mOpenCvCameraView;
    private ImageView imgView;
    private TextView lblCount;
    private ImageButton btnFlash, btnCapture, btnSetting;
    private Mat mRgba;
    private boolean isFlashEnable = false;
    RelativeLayout mContainerView;
    LayoutInflater inflater;
    View settingView;
    SeekBar hMin, hMax, sMin, sMax, vMin, vMax;
    int count = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mOpenCvCameraView = (CameraView) findViewById(R.id.surface_view);
        mOpenCvCameraView.setCvCameraViewListener(this);
        mOpenCvCameraView.setFocusable(true);

        imgView = (ImageView) findViewById(R.id.imageView);
        btnFlash = (ImageButton) findViewById(R.id.btnFlash);
        btnSetting = (ImageButton) findViewById(R.id.btnSetting);


        //set size of camera view
        int width = 800;
        int height = 450;
        mOpenCvCameraView.setMinimumHeight(height);
        mOpenCvCameraView.setMinimumWidth(width);
        mOpenCvCameraView.setMaxFrameSize(width, height);


        //mOpenCvCameraView.enableFpsMeter();
        CheckFlashlight();
        LoadSetting();


        mContainerView = (RelativeLayout)findViewById(R.id.mainview);
        inflater =(LayoutInflater)getSystemService(this.LAYOUT_INFLATER_SERVICE);
        settingView = inflater.inflate(R.layout.activity_setting, null);


        //TODO: add ads
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                {
                    mOpenCvCameraView.enableView();
                    mOpenCvCameraView.setOnTouchListener(MainActivity.this);
                } break;
                default:
                {
                    super.onManagerConnected(status);
                } break;
            }
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////

    @Override
    public void onPause()
    {
        super.onPause();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    @Override
    public void onResume()
    {
        super.onResume();
        if (!OpenCVLoader.initDebug()) {
            Log.d(Common.d, "Internal OpenCV library not found. Using OpenCV Manager for initialization");
            OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_3_0_0, this, mLoaderCallback);
        } else {
            Log.d(Common.d, "OpenCV library found inside package. Using it!");
            mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public Mat onCameraFrame(CvCameraViewFrame inputFrame) {
        if(count <3)
            count++;
        else
        {
            count = 0;
            inputFrame.rgba().copyTo(mRgba);
            mRgba = Tracking.DetectColor(mRgba);
        }
        return mRgba;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void onDestroy() {
        super.onDestroy();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void onCameraViewStopped()
    {
        mRgba.release();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public boolean onTouch(View v, MotionEvent event)
    {
        return true;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void onCameraViewStarted(int width, int height)
    {
        //Log.d(Common.d + "onCameraViewStarted", String.valueOf(width) + " " + String.valueOf(height) );
        mRgba = new Mat(height, width, CvType.CV_8UC4);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void btnFlash_onClick(View v)
    {
        if(isFlashEnable)
        {
            btnFlash.setImageResource(R.drawable.noflash256);
        }
        else
        {
            btnFlash.setImageResource(R.drawable.flash256);
        }
        mOpenCvCameraView.setupCameraFlashLight();
        isFlashEnable = !isFlashEnable;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void btnSetting_onClick(View v)
    {
        mContainerView.addView(settingView);

        SetMainViewVisibility(false);

        if(hMin == null) {
            hMin = (SeekBar) findViewById(R.id.hMin);
            hMin.setProgress(Common.hMin);
        }
        if(hMax == null) {
            hMax = (SeekBar) findViewById(R.id.hMax);
            hMax.setProgress(Common.hMax);
        }
        if(sMin == null) {
            sMin = (SeekBar) findViewById(R.id.sMin);
            sMin.setProgress(Common.sMin);
        }
        if(sMax == null){
            sMax = (SeekBar) findViewById(R.id.sMax);
            sMax.setProgress(Common.sMax);
        }
        if(vMin == null) {
            vMin = (SeekBar) findViewById(R.id.vMin);
            vMin.setProgress(Common.vMin);
        }
        if(vMax == null) {
            vMax = (SeekBar) findViewById(R.id.vMax);
            vMax.setProgress(Common.vMax);
        }


        hMin.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progressValue, boolean fromUser)
            {
                Common.hMin = progressValue;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}
        });

        hMax.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progressValue, boolean fromUser)
            {
                Common.hMax = progressValue;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}
        });

        sMin.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progressValue, boolean fromUser)
            {
                Common.sMin = progressValue;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}
        });

        sMax.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progressValue, boolean fromUser)
            {
                Common.sMax = progressValue;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}
        });

        vMin.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener()
        {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progressValue, boolean fromUser)
            {
                Common.vMin = progressValue;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}
        });
        vMax.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progressValue, boolean fromUser) {
                Common.vMax = progressValue;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) { }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) { }
        });
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void btnBack_onClick(View v)
    {
        HideSettingLayout();
        SaveSetting();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    void HideSettingLayout()
    {
        mContainerView.removeView(settingView);
        SetMainViewVisibility(true);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    @Override
    public void onBackPressed()
    {
        if(imgView.getVisibility()==View.VISIBLE)
        {
            imgView.setVisibility(View.INVISIBLE);
            return;
        }
        if(mContainerView.getChildCount() > 7)
        {
            HideSettingLayout();
            SaveSetting();
            return;
        }
        ShowExitDialog();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    private void ShowExitDialog()
    {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("Bạn muốn thoát chương trình?") //
                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        // TODO
                        System.exit(0);
                        dialog.dismiss();
                    }
                }) //
                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        // TODO
                        dialog.dismiss();
                    }
                });
        builder.show();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    private void CheckFlashlight()
    {
        if(!this.getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA_FLASH))
            btnFlash.setVisibility(View.GONE);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    void LoadSetting()
    {
        SharedPreferences pre=getSharedPreferences(Common.prefname, MODE_PRIVATE);

        Common.hMin = pre.getInt("hMin", 0);
        Common.hMax = pre.getInt("hMax", 255);

        Common.sMin = pre.getInt("sMin", 0);
        Common.sMax = pre.getInt("sMax", 255);

        Common.vMin = pre.getInt("vMin", 0);
        Common.vMax = pre.getInt("vMax", 255);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    void SaveSetting()
    {
        SharedPreferences pre=getSharedPreferences(Common.prefname, MODE_PRIVATE);
        SharedPreferences.Editor editor=pre.edit();

        editor.putInt("hMin", Common.hMin);
        editor.putInt("hMax", Common.hMax);

        editor.putInt("sMin", Common.sMin);
        editor.putInt("sMax", Common.sMax);

        editor.putInt("vMin", Common.vMin);
        editor.putInt("vMax", Common.vMax);

        editor.commit();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    public void btnReset_onClick(View v)
    {
        hMin.setProgress(0);
        sMin.setProgress(0);
        vMin.setProgress(0);
        hMax.setProgress(255);
        sMax.setProgress(255);
        vMax.setProgress(255);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////

    private void SetMainViewVisibility(boolean enable) {
        if (enable)
        {
            btnFlash.setVisibility(View.VISIBLE);
            btnSetting.setVisibility(View.VISIBLE);
        }
        else
        {
            btnFlash.setVisibility(View.INVISIBLE);
            btnSetting.setVisibility(View.INVISIBLE);
        }
    }
}
