#include <highgui.h>
#include <cv.h>

int main()
{
IplImage *src, *dst;
src=cvLoadImage("yao.jpg");
dst=cvCreateImage(cvGetSize(src),IPL_DEPTH_16S,3);
cvNamedWindow("showsrc",0);

cvShowImage("showscr",src);
cvNamedWindow ("showdst",0);

cvLaplace(src,dst,7);
cvShowImage("showdst",dst);
cvWaitKey(0);
cvReleaseImage( &src );  
       cvReleaseImage( &dst );  
return 0;
}

