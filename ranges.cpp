#include"cv.h"
#include"highgui.h"
#include"ctype.h"

int hmax=0,hmin=0,smax=0,smin=0,vmax=0,vmin=0;
int main(int argc,char** argv)
{
IplImage*image,*hue,*mask,*hsv;

int _hmax=0,_hmin=0,_smax=0,_smin=0,_vmax=0,_vmin=0;
cvNamedWindow("image",0);
cvNamedWindow("hsv",0);
cvNamedWindow("mask",0);
cvNamedWindow("track",0);
cvCreateTrackbar("hmax","track",&hmax,256,0);
cvCreateTrackbar("hmin","track",&hmin,256,0);
cvCreateTrackbar("smax","track",&smax,256,0);
cvCreateTrackbar("smin","track",&smin,256,0);
cvCreateTrackbar("vmax","track",&vmax,256,0);
cvCreateTrackbar("vmin","track",&vmin,256,0);

image=cvLoadImage("lena.jpg");
hsv=cvCreateImage(cvGetSize(image),8,3);
mask=cvCreateImage(cvGetSize(image),8,1);
cvCvtColor(image,hsv,CV_RGB2BGR);
cvShowImage("image",image);
cvShowImage("hsv",hsv);


int flag=0;
while(flag!='q')
{
_hmax=hmax,_hmin=hmin,_smax=smax,_smin=smin,_vmax=vmax,_vmin=vmin;
cvInRangeS(hsv,cvScalar(MIN(_hmax,_hmin),MIN(_smax,_smin),MIN(_vmin,_vmax),0),cvScalar(MAX(_hmax,_hmin),MAX(_smax,_smin),MAX(_vmin,_vmax),0),mask);
cvShowImage("mask",mask);
flag=cvWaitKey(40);

}
cvDestroyAllWindows();
cvReleaseImage(&image);
cvReleaseImage(&hsv);
cvReleaseImage(&mask);

return 0;
}
