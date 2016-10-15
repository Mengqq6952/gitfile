#include<highgui.h>
#include<cv.h>

int main(int argc, char **agrv)
{
IplImage *src,*dst;
src=cvLoadImage("lena.jpg",0);
dst=cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);
cvNamedWindow("src",0);
cvNamedWindow("dst",0);
cvShowImage("src",src);
cvCanny(src,dst,50,10,3);
cvShowImage("dst",dst);
cvWaitKey(0);
cvReleaseImage(&src);
cvReleaseImage(&dst);
}

