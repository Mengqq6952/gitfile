#include <highgui.h>  
#include <cv.h>  
  
int main(int argc, char** argv)  
{  
    int i;  
    IplImage* src = cvLoadImage( argv[1], 1 );  
    IplImage* imgChannel[4] = { 0, 0, 0, 0 };  
    IplImage* dst = cvCreateImage( cvGetSize( src ), IPL_DEPTH_8U, 3 );  
  
    if( src )  
    {  
        for( i = 0; i < src -> nChannels; i++ )  
        {  
            imgChannel[i] = cvCreateImage( cvGetSize( src ), IPL_DEPTH_8U, 1 );  
        }  
         
        cvSplit( src, imgChannel[0], imgChannel[1], imgChannel[2], imgChannel[3] );
        for( i = 0; i < dst -> nChannels; i++ )  
        {  
            
            cvEqualizeHist( imgChannel[i], imgChannel[i] );  
        }  
    
        cvMerge( imgChannel[0], imgChannel[1], imgChannel[2], imgChannel[3], dst );  
        cvNamedWindow( "src", 1 );  
        cvShowImage( "src", src );  
        cvNamedWindow( "Equalize", 1 );  
        cvShowImage( "Equalize", dst );  
  
        cvWaitKey(0);  
    
        for( i = 0; i < src -> nChannels; i++ )  
        {  
            if( imgChannel[i] )  
            {  
                cvReleaseImage( &imgChannel[i] );  
                
            }  
        }  
        cvReleaseImage( &dst );  
    }  
  
    return 0;  
}  
