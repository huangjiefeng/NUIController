#include "Controller.h"
#include <Windows.h>
#include <Kinect.h>
#include <Kinect.VisualGestureBuilder.h>
#include <opencv2/opencv.hpp>
#pragma comment ( lib, "Kinect20.VisualGestureBuilder.lib" )
#include "dbus/CvCoreIf.h"
#include "dbus/CvCoreServiceCommon.h"
#include "Util/Common.h"
#include "config/Main_config.h"
#include <iostream>
#include <string>
//#include <QApplication>
//#include "Util/Format.h"
#include <QtCore/QString>
#include "libini.h"


Controller::Controller(void)
{
	// 加载主配置文件  
	if (!Main_config::instance().load_config())  
	{  
		std::cout << "Main_config::load_config() failed" << std::endl;  
		return ;  
	}  
	//从配置文件中读取
	std::string str;
	wchar_t strW[GESTURE_NAME_LENGTH];
	Main_config::instance().get_config().Read("33LayoutGesture", str); 
	//wcsncpy(strW,str.c_str(),GESTURE_NAME_LENGTH);
	//ThreeThreeLayouGesture.fromStdString(str);
	
	pini = ini_open("config.ini");
	if (!pini) {
		printf("load config faild.\n");
		return ;
	}
}


Controller::~Controller(void)
{
	ini_close(pini);
}

void Controller::sendToDBus(CoreAction action,int argument)
{
	CvCoreIf *coreIf = new CvCoreIf( CVCORE_SERVICE_NAME , CVCORE_SERVICE_OBJECT_PATH , QDBusConnection::sessionBus() );
	QByteArray output_bytes;
	QDataStream out( &output_bytes, QIODevice::WriteOnly );
	out.setVersion(QDataStream::Qt_4_4 );

	switch (action)
	{
	case CoreAction_SendQoS:
		break;
	case CoreAction_StartRecvStreamedMedia:
		break;
	case CoreAction_StopRecvStreamedMedia:
		break;
	case CoreAction_SetVolume:
		{
			QString direction="out";
			int volumn = argument;
			out<<direction<<volumn;
		}
		break;
	case CoreAction_ShutDown:
		break;
	case CoreAction_Restart:
		break;
	case CoreAction_ChangeMediaWindowPosition:
		break;
	case CoreAction_StopLocalAudio:
		break;
	case CoreAction_StopLocalVideo:
		break;
	case CoreAction_StartSendScreenMedia:
		break;
	case CoreAction_StartRecvScreenMedia:
		break;
	case CoreAction_StopRecvScreenMedia:
		break;
	case CoreAction_ControlAudioRecv:
		break;
	case CoreAction_ControlVideoRecv:
		break;
	case CoreAction_EnterMeeting:
		break;
	case CoreAction_ChangeLayout:
		//设置布局
		{
			int screen_index = 0;
			int layout_index =  argument;
			out << screen_index << layout_index;
			break;
		}

	case CoreAction_QuitMeeting:
		break;
	case CoreAction_CloseScreenRecv:
		break;
	case CoreAction_OpenScreenShare:
		break;
	case CoreAction_CloseScreenShare:
		break;
	case CoreAction_ShareScreenControl:
		break;
	case CoreAction_PPTControlCommand:
		break;
	case CoreAction_GetTerminalConfig:
		break;
	case CoreAction_SetPanelVisible:
		{
			bool visible = argument;
			out<<visible;
			break;
		}
		break;
	case CoreAction_GetPannelState:
		break;
	case CoreAction_RecvMonitorCofinfo:
		break;
	case CoreAction_RecoveryMeidaProcess:
		break;
	case CoreAction_SegmentVideo:
		break;
	case CoreAction_ControlVideoRecord:
		break;
	default:
		break;
	}

	coreIf->TeleCommand(action,output_bytes);

}

bool Controller::startRecgonize()
{
		cv::setUseOptimized( true );

	// Sensor
	IKinectSensor* pSensor;
	HRESULT hResult = S_OK;
	hResult = GetDefaultKinectSensor( &pSensor );
	if( FAILED( hResult ) ){
		std::cerr << "Error : GetDefaultKinectSensor" << std::endl;
		return -1;
	}

	hResult = pSensor->Open();
	if( FAILED( hResult ) ){
		std::cerr << "Error : IKinectSensor::Open()" << std::endl;
		return -1;
	}

	// Source
	IColorFrameSource* pColorSource;
	hResult = pSensor->get_ColorFrameSource( &pColorSource );
	if( FAILED( hResult ) ){
		std::cerr << "Error : IKinectSensor::get_ColorFrameSource()" << std::endl;
		return -1;
	}

	IBodyFrameSource* pBodySource;
	hResult = pSensor->get_BodyFrameSource( &pBodySource );
	if( FAILED( hResult ) ){
		std::cerr << "Error : IKinectSensor::get_BodyFrameSource()" << std::endl;
		return -1;
	}



	// Reader
	IColorFrameReader* pColorReader;
	hResult = pColorSource->OpenReader( &pColorReader );
	if( FAILED( hResult ) ){
		std::cerr << "Error : IColorFrameSource::OpenReader()" << std::endl;
		return -1;
	}

	IBodyFrameReader* pBodyReader;
	hResult = pBodySource->OpenReader( &pBodyReader );
	if( FAILED( hResult ) ){
		std::cerr << "Error : IBodyFrameSource::OpenReader()" << std::endl;
		return -1;
	}



	// Description
	IFrameDescription* pDescription;
	hResult = pColorSource->get_FrameDescription( &pDescription );
	if( FAILED( hResult ) ){
		std::cerr << "Error : IColorFrameSource::get_FrameDescription()" << std::endl;
		return -1;
	}

	int width = 0;
	int height = 0;
	pDescription->get_Width( &width ); // 1920
	pDescription->get_Height( &height ); // 1080
	unsigned int bufferSize = width * height * 4 * sizeof( unsigned char );

	cv::Mat bufferMat( height, width, CV_8UC4 );
	cv::Mat bodyMat( height / 2, width / 2, CV_8UC4 );
	cv::namedWindow( "Gesture" );

	// Color Table
	cv::Vec3b color[BODY_COUNT];
	color[0] = cv::Vec3b( 255, 0, 0 );
	color[1] = cv::Vec3b( 0, 255, 0 );
	color[2] = cv::Vec3b( 0, 0, 255 );
	color[3] = cv::Vec3b( 255, 255, 0 );
	color[4] = cv::Vec3b( 255, 0, 255 );
	color[5] = cv::Vec3b( 0, 255, 255 );

	// Coordinate Mapper
	ICoordinateMapper* pCoordinateMapper;
	hResult = pSensor->get_CoordinateMapper( &pCoordinateMapper );
	if( FAILED( hResult ) ){
		std::cerr << "Error : IKinectSensor::get_CoordinateMapper()" << std::endl;
		return -1;
	}

	IVisualGestureBuilderFrameSource* pGestureSource[BODY_COUNT];
	IVisualGestureBuilderFrameReader* pGestureReader[BODY_COUNT];
	for( int count = 0; count < BODY_COUNT; count++ ){
		// Source
		hResult = CreateVisualGestureBuilderFrameSource( pSensor, 0, &pGestureSource[count] );
		if( FAILED( hResult ) ){
			std::cerr << "Error : CreateVisualGestureBuilderFrameSource()" << std::endl;
			return -1;
		}

		// Reader
		hResult = pGestureSource[count]->OpenReader( &pGestureReader[count] );
		if( FAILED( hResult ) ){
			std::cerr << "Error : IVisualGestureBuilderFrameSource::OpenReader()" << std::endl;
			return -1;
		}
	}

	//// Create Gesture Dataase from File (*.gba)
	//IVisualGestureBuilderDatabase* pGestureDatabase;
	//hResult = CreateVisualGestureBuilderDatabaseInstanceFromFile( L"HandsOpen.gba"/*L"Swipe.gba"*/, &pGestureDatabase );
	//if( FAILED( hResult ) ){
	//	std::cerr << "Error : CreateVisualGestureBuilderDatabaseInstanceFromFile()" << std::endl;
	//	return -1;
	//}
	IVisualGestureBuilderDatabase* pGestureDatabase;
	hResult = CreateVisualGestureBuilderDatabaseInstanceFromFile( L"AllGestures.gbd"/*L"Swipe.gba"*/, &pGestureDatabase );
	if( FAILED( hResult ) ){
		std::cerr << "Error : CreateVisualGestureBuilderDatabaseInstanceFromFile()" << std::endl;
		return -1;
	}

	// Add Gesture
	UINT gestureCount = 0;
	hResult = pGestureDatabase->get_AvailableGesturesCount( &gestureCount );
	if( FAILED( hResult ) || !gestureCount ){
		std::cerr << "Error : IVisualGestureBuilderDatabase::get_AvailableGesturesCount()" << std::endl;
		return -1;
	}

	IGesture* ppGesture[10];
	hResult = pGestureDatabase->get_AvailableGestures( gestureCount, ppGesture );
	
	if( SUCCEEDED( hResult ) && ppGesture != nullptr ){
		for( int count = 0; count < BODY_COUNT; count++ ){
			for (int i=0;i<gestureCount;i++)
			{
				hResult = pGestureSource[count]->AddGesture( ppGesture[i] );
				if( FAILED( hResult ) ){
					std::cerr << "Error : IVisualGestureBuilderFrameSource::AddGesture()" << std::endl;
					return -1;
				}

				hResult = pGestureSource[count]->SetIsEnabled( ppGesture[i], true );
				if( FAILED( hResult ) ){
					std::cerr << "Error : IVisualGestureBuilderFrameSource::SetIsEnabled()" << std::endl;
					return -1;
				}
			}

		}
	}

	while( 1 ){
		// Frame
		IColorFrame* pColorFrame = nullptr;
		hResult = pColorReader->AcquireLatestFrame( &pColorFrame );
		if( SUCCEEDED( hResult ) ){
			hResult = pColorFrame->CopyConvertedFrameDataToArray( bufferSize, reinterpret_cast<BYTE*>( bufferMat.data ), ColorImageFormat::ColorImageFormat_Bgra );
			if( SUCCEEDED( hResult ) ){
				cv::resize( bufferMat, bodyMat, cv::Size(), 0.5, 0.5 );
			}
		}
		SafeRelease( pColorFrame );

		IBodyFrame* pBodyFrame = nullptr;
		hResult = pBodyReader->AcquireLatestFrame( &pBodyFrame );
		if( SUCCEEDED( hResult ) ){
			IBody* pBody[BODY_COUNT] = { 0 };
			hResult = pBodyFrame->GetAndRefreshBodyData( BODY_COUNT, pBody );
			if( SUCCEEDED( hResult ) ){
				for( int count = 0; count < BODY_COUNT; count++ ){
					BOOLEAN bTracked = false;
					hResult = pBody[count]->get_IsTracked( &bTracked );
					if( SUCCEEDED( hResult ) && bTracked ){
						// Joint
						Joint joint[JointType::JointType_Count];
						hResult = pBody[count]->GetJoints( JointType::JointType_Count, joint );
						if( SUCCEEDED( hResult ) ){
							for( int type = 0; type < JointType::JointType_Count; type++ ){
								ColorSpacePoint colorSpacePoint = { 0 };
								pCoordinateMapper->MapCameraPointToColorSpace( joint[type].Position, &colorSpacePoint );
								int x = static_cast<int>( colorSpacePoint.X );
								int y = static_cast<int>( colorSpacePoint.Y );
								if( ( x >= 0 ) && ( x < width ) && ( y >= 0 ) && ( y < height ) ){
									cv::circle( bufferMat, cv::Point( x, y ), 5, static_cast< cv::Scalar >( color[count] ), -1, CV_AA );
								}
							}
						}

						// Set TrackingID to Detect Gesture
						UINT64 trackingId = _UI64_MAX;
						hResult = pBody[count]->get_TrackingId( &trackingId );
						if( SUCCEEDED( hResult ) ){
							pGestureSource[count]->put_TrackingId( trackingId );
						}
					}
				}
				cv::resize( bufferMat, bodyMat, cv::Size(), 0.5, 0.5 );
			}
			for( int count = 0; count < BODY_COUNT; count++ ){
				SafeRelease( pBody[count] );
			}
		}
		SafeRelease( pBodyFrame );

		// Detect Gesture
		std::system( "cls" );
		for( int count = 0; count < BODY_COUNT; count++ ){
			IVisualGestureBuilderFrame* pGestureFrame = nullptr;
			hResult = pGestureReader[count]->CalculateAndAcquireLatestFrame( &pGestureFrame );
			if( SUCCEEDED( hResult ) && pGestureFrame != nullptr ){
				BOOLEAN bGestureTracked = false;
				hResult = pGestureFrame->get_IsTrackingIdValid( &bGestureTracked );
				if( SUCCEEDED( hResult ) && bGestureTracked ){
					// Discrete Gesture (Sample HandUp.gba is Action to Hand Up above the head.)
					IDiscreteGestureResult* pGestureResult = nullptr;
					for (int i=0;i<gestureCount;i++)
					{
						IGesture *pDetectGesture = ppGesture[i];
						hResult = pGestureFrame->get_DiscreteGestureResult( pDetectGesture, &pGestureResult );

						if( SUCCEEDED( hResult ) && pGestureResult != nullptr ){
							BOOLEAN bDetected = false;
							hResult = pGestureResult->get_Detected( &bDetected );
							if( SUCCEEDED( hResult ) && bDetected ){
								//可能会导致内存泄漏？
								/*GestureType *pType;
								pDetectGesture->get_GestureType(pType);*/
								wchar_t *name = new wchar_t[GESTURE_NAME_LENGTH];
								pDetectGesture->get_Name(GESTURE_NAME_LENGTH,name);
								QString strGestureName;
								strGestureName = QString::fromWCharArray(name);
								std::cout << "Detected Gesture" <<i<< std::endl;
								
								//QString strGestureNameFromConfig(Main_config::instance().get_config().Read<std::string>("33LayoutGesture").c_str());
							/*	std::string action ;
								action = Main_config::instance().get_config().Read<std::string>(strGestureName.toStdString(),action);
							*/	
								char action[GESTURE_NAME_LENGTH]={};
								ini_get(pini,strGestureName.toStdString().c_str(),action);
								
								if (strncmp(action,"Layout11",GESTURE_NAME_LENGTH)==0)
								{
									sendToDBus(CoreAction_ChangeLayout,	kLayoutOf1x1);
									
								}
								else if (strncmp(action,"Layout22",GESTURE_NAME_LENGTH)==0)
								{
									sendToDBus(CoreAction_ChangeLayout,	kLayoutOf2x2);
								}
								else  if (strncmp(action,"Layout33",GESTURE_NAME_LENGTH)==0)
								{
									sendToDBus(CoreAction_ChangeLayout,	kLayoutOf3x3);
								}
								else if (strncmp(action,"PanelVisible",GESTURE_NAME_LENGTH)==0)			
								{
									sendToDBus(CoreAction_SetPanelVisible,1);
								}
								else if (strncmp(action,"PanelUnvisible",GESTURE_NAME_LENGTH)==0)			
								{
									sendToDBus(CoreAction_SetPanelVisible,	0);
								}
								else if (strncmp(action,"VolumnUp",GESTURE_NAME_LENGTH)==0)			
								{
									sendToDBus(CoreAction_SetVolume,90);
								}
								else if (strncmp(action,"VolumnDown",GESTURE_NAME_LENGTH)==0)			
								{
									sendToDBus(CoreAction_SetVolume,10);
								}
								else if (strncmp(action,"PPTPrev",GESTURE_NAME_LENGTH)==0)			
								{
									sendToDBus(CoreAction_PPTControlCommand,1);
								
								}
								else if (strncmp(action,"PPTNext",GESTURE_NAME_LENGTH)==0)			
								{
									sendToDBus(CoreAction_PPTControlCommand,0);
									
								}
								Sleep(2000);
							
								/*		switch (i)
								{
								case 0:
								sendToDBus(CoreAction_ChangeLayout,	kLayoutOf1x1);
								Sleep(1000);
								break;
								case 1:
								sendToDBus(CoreAction_SetPanelVisible,1);
								Sleep(1000);

								break;
								case 2:
								sendToDBus(CoreAction_SetPanelVisible,	0);
								Sleep(1000);

								break;
								case 3:
								sendToDBus(CoreAction_ChangeLayout,	kLayoutOf2x2);
								Sleep(1000);
								break;
								case 4:
								sendToDBus(CoreAction_ChangeLayout,	kLayoutOf3x3);
								Sleep(1000);

								break;

								}*/


							}
						}

					}


					/*// Continuous Gesture (Sample Swipe.gba is Action to Swipe the hand in horizontal direction.)
					IContinuousGestureResult* pGestureResult = nullptr;
					hResult = pGestureFrame->get_ContinuousGestureResult( pGesture, &pGestureResult );
					if( SUCCEEDED( hResult ) && pGestureResult != nullptr ){
						float progress = 0.0f;
						hResult = pGestureResult->get_Progress( &progress );
						if( SUCCEEDED( hResult ) ){
							std::cout << "Progress: " + std::to_string( progress ) << std::endl;
						}
					}*/

					SafeRelease( pGestureResult );

				}
			}
			SafeRelease( pGestureFrame );
		}

		cv::imshow( "Gesture", bodyMat );

		if( cv::waitKey( 10 ) == VK_ESCAPE ){
			break;
		}
	}

	SafeRelease( pColorSource );
	SafeRelease( pBodySource );
	SafeRelease( pColorReader );
	SafeRelease( pBodyReader );
	SafeRelease( pDescription );
	SafeRelease( pCoordinateMapper );
	for( int count = 0; count < BODY_COUNT; count++ ){
		SafeRelease( pGestureSource[count] );
		SafeRelease( pGestureReader[count] );
	}
	SafeRelease( pGestureDatabase );
	for (int i=0;i<gestureCount;i++)
	{
		SafeRelease( ppGesture[i] );

	}
	if( pSensor ){
		pSensor->Close();
	}
	SafeRelease( pSensor );
	cv::destroyAllWindows();

	return true;

}
