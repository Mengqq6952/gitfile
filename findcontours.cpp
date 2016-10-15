#include "highgui.h"
#include "cv.h"
#include "iomanip"

using namespace std;

int main()
{
    int i=0;
    
    int contours_num=0;
    CvMemStorage *storage=cvCreateMemStorage(0);
    CvSeq *contour =0;

    IplImage *img=cvLoadImage("lena.jpg",0);
    cvThreshold(img,img,128,255,CV_THRESH_BINARY);
    IplImage *pContourImg = cvCreateImage(cvGetSize(img),
        IPL_DEPTH_8U,3);
    cvNamedWindow("windows",1);
    cvShowImage("windows",img);
    

    contours_num=cvFindContours(img,storage,&contour,
        sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
    

    
    CvSeqReader reader;
    int count=0;
    if (contour!=0)
    {
        count=contour->total;
       
    }

    cvStartReadSeq(contour,&reader,0);
    CvPoint pt1;
    CvScalar color=CV_RGB(255,255,255);
    cvNamedWindow("contour",1);
    cvShowImage("contour",pContourImg);
    for (i=0;i<count;i++)
{
        CV_READ_SEQ_ELEM(pt1,reader);
        cvCircle(pContourImg,pt1,1,color);
        cvShowImage("contour",pContourImg);
        cvWaitKey(5);
    }
    cvWaitKey(0);

    cvReleaseImage(&img);
    cvReleaseImage(&pContourImg);
    cvReleaseMemStorage(&storage);
    return 0;
}



