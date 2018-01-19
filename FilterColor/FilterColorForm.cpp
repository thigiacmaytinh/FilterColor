#include "stdafx.h"
#include "FilterColorForm.h"
#include "TGMTbridge.h"
#include "TGMTblob.h"
#include "TGMTutil.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace std;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace System::IO;
using namespace TGMT;

static cv::Mat m_matInput;
static cv::Mat m_matMask;

void FilterColorForm::FilterColor()
{
	cv::Mat matBlur = m_matInput.clone();

	if (m_blurSize > 0)
	{
		cv::blur(matBlur, matBlur, cv::Size(m_blurSize, m_blurSize));
	}
	
	cv::Mat imgHSV;
	cv::cvtColor(matBlur, imgHSV, cv::COLOR_BGR2HSV);

	cv::Scalar lower = cv::Scalar(iLowH, iLowS, iLowV);
	cv::Scalar higher = cv::Scalar(iHighH, iHighS, iHighV);

	cv::Mat imgResult;
	cv::inRange(imgHSV, lower, higher, m_matMask);
	cv::imshow("Mask", m_matMask);

	m_matInput.copyTo(imgResult, m_matMask);


	cv::imshow("output", imgResult);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::txtFilePath_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (File::Exists(txtFilePath->Text))
	{
		m_matInput = cv::imread(TGMTbridge::SystemStr2stdStr(txtFilePath->Text));
		cv::imshow("Input image", m_matInput);

		trackBar1->Enabled = true;
		trackBar2->Enabled = true;
		trackBar3->Enabled = true;
		trackBar4->Enabled = true;
		trackBar5->Enabled = true;
		trackBar6->Enabled = true;
		trackBar7->Enabled = true;

		FilterColor();
	}
		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::btnBrowse_Click(System::Object^  sender, System::EventArgs^  e) 
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Multiselect = false;
	ofd->Filter = "Image file |*.jpg;*.jpg;*.png;*.PNG;*.bmp;*.BMP;*.webp;*.WEBP";
	ofd->ShowDialog();
	if (ofd->FileName != "")
		txtFilePath->Text = ofd->FileName;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::FilterColorForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	this->KeyPreview = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) 
{
	iLowH = trackBar1->Value;
	numHmin->Text = "" + trackBar1->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) 
{
	iHighH = trackBar2->Value;
	numHmax->Text = "" + trackBar2->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	iLowS = trackBar3->Value;
	numSmin->Text = "" + trackBar3->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) 
{
	iHighS = trackBar4->Value;
	numSmax->Text = "" + trackBar4->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	iLowV = trackBar5->Value;
	numVmin->Text = "" + trackBar5->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::trackBar6_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	iHighV = trackBar6->Value;
	numVmax->Text = "" + trackBar6->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::trackBar7_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	if (trackBar7->Value > 0)
		m_blurSize = trackBar7->Value * 2 + 1;
	else
		m_blurSize = 0;
	lblBlur->Text = "" + m_blurSize;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::numHmin_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	trackBar1->Value = (int)numHmin->Value;
	iLowH = (int)numHmin->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::numHmax_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	trackBar2->Value = (int)numHmax->Value;
	iHighH = (int)numHmax->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::numSmin_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	trackBar3->Value = (int)numSmin->Value;
	iLowS = (int)numSmin->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::numSmax_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	trackBar4->Value = (int)numSmax->Value;
	iHighS = (int)numSmax->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::numVmin_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	trackBar5->Value = (int)numVmin->Value;
	iLowV = (int)numVmin->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::numVmax_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
	trackBar6->Value = (int)numVmax->Value;
	iHighV = (int)numVmax->Value;
	FilterColor();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::FilterColorForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	if(e->Control && e->KeyCode == Keys::C)
		Clipboard::SetText("" + iLowH + "," + iHighH + "," + iLowS  + "," + iHighS + "," +  iLowV + "," + iHighV);
	else if (e->Control && e->KeyCode == Keys::V)
	{
		String^ text = Clipboard::GetText();
		auto split = text->Split(',');
		if (split->Length != 6)
			return;

		if (!m_matInput.data)
			return;

		numHmin->Value = Convert::ToInt32(split[0]);
		numHmax->Value = Convert::ToInt32(split[1]);
		numSmin->Value = Convert::ToInt32(split[2]);
		numSmax->Value = Convert::ToInt32(split[3]);
		numVmin->Value = Convert::ToInt32(split[4]);
		numVmax->Value = Convert::ToInt32(split[5]);
		FilterColor();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void FilterColorForm::btnCount_Click(System::Object^  sender, System::EventArgs^  e)
{
	std::vector<TGMTblob::Blob> blobs = TGMTblob::FindBlobs(m_matMask.clone());
	std::string count = TGMTutil::FormatString("%d", blobs.size());
	lblCount->Text = TGMTbridge::stdStrToSystemStr(count);
}