#pragma once

#define CVCORE_SERVICE_NAME			"com.dcampus.coolview.core"
#define CVCORE_SERVICE_OBJECT_PATH	"/com/dcampus/coolview/core"


enum CoreAction
{
	CoreAction_SendQoS,
	CoreAction_StartRecvStreamedMedia,		//��ʼ����ĳһ·��Ƶ��
	CoreAction_StopRecvStreamedMedia,		//ֹͣ����ĳһ·��Ƶ��
	CoreAction_SetVolume,					//�����ն�����
	CoreAction_ShutDown,					//�˳�CoolView
	CoreAction_Restart,						//����CoolView
	CoreAction_ChangeMediaWindowPosition,	//����ý�崰�ڵ�λ��
	CoreAction_StopLocalAudio,				//ֹͣ���ն˵���Ƶ����
	CoreAction_StopLocalVideo,				//ֹͣ���ն˵���Ƶ����
	CoreAction_StartSendScreenMedia,		//����������Ļ��
	CoreAction_StartRecvScreenMedia,		//����������Ļ��������ΪmemberUR��screenIndex
	CoreAction_StopRecvScreenMedia,			//ֹͣ������Ļ��������ΪmemberUR��screenIndex
	CoreAction_ControlAudioRecv,			//���ƽ���Զ���ն���Ƶ������ΪmemberUR��enable
	CoreAction_ControlVideoRecv,			//���ƽ���Զ���ն���Ƶ������ΪmemberUR��enable
	CoreAction_EnterMeeting,				//ң���ն˽���ָ������
	CoreAction_ChangeLayout,				//ң���ն˸ı䲼��
	CoreAction_QuitMeeting,					//ң���ն��˳�����
	CoreAction_CloseScreenRecv,             //��Ļ������չر�
	CoreAction_OpenScreenShare,				//ң���ն˴���Ļ����
	CoreAction_CloseScreenShare,            //ң���ն�ֹͣ��Ļ����
	CoreAction_ShareScreenControl,			//����������Ϳ�����رչ�����Ļ��Ϣ��֪ͨ�������������ն˿�����رս�����Ļ����
	CoreAction_PPTControlCommand,			//ִ��PPTҳ��ı�ָ��
	CoreAction_GetTerminalConfig,           //ң������ȡ�ն���������
	CoreAction_SetPanelVisible,             //�����ն˿��������ʾ���
	CoreAction_GetPannelState ,             //��ȡ�ն˿��������ʾ���
	CoreAction_RecvMonitorCofinfo ,         //�Ӽ��ģ���н��յ������Ϣ
	CoreAction_RecoveryMeidaProcess,        //�ָ�ý�����
	CoreAction_SegmentVideo,                //��Ƶ�ֶΣ�������Tx���ͷּ���Ϣ
	CoreAction_ControlVideoRecord,          //��Ƶ¼�ƿ���
};