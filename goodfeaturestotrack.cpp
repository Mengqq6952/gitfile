#include"cv.h"
#include"highgui.h"
#include"stdio.h"
#define max_corners 50

int main(int argc,char** argv)
{
 int cornerCount=max_corners;
 CvPoint2D32f corners[max_corners];
 double qualityLevel=0.05;
 double minDistance=5;
 IplImage* srcImage=0,*grayImage=0,*corners1=0,*corners2=0;
 int i;
 CvScalar color=CV_RGB(255,0,0);
 cvNamedWindow("image",1);
 srcImage=cvLoadImage("lena.jpg",1);
 grayImage=cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U,1);
 cvCvtColor(srcImage,grayImage,CV_BGR2GRAY);
 corners1=cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_32F,1);
 corners2=cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_32F,1);
 cvGoodFeaturesToTrack(grayImage,corners1,corners2,corners,&cornerCount,qualityLevel,minDistance,0);
 printf("num corners found:%d\n",cornerCount);
 if(cornerCount>0)
 {
	 for(i=0;i<cornerCount;i++){
		 cvCircle(srcImage,cvPoint((int)(corners[i].x),(int)(corners[i].y)),6,color,2,CV_AA,0);
	 }
 }

cvShowImage("image",srcImage);
cvReleaseImage(&srcImage);
cvReleaseImage(&grayImage);
//cvReleaseImage(&corners1);
//cvReleaseImage(&corners2);
cvWaitKey(0);
return 0;
}
