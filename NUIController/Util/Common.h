#define GESTURE_NAME_LENGTH 1000 //��Ϊ100�Ͷ�ȡ����

template<class Interface>
inline void SafeRelease( Interface *& pInterfaceToRelease )
{
	if( pInterfaceToRelease != NULL ){
		pInterfaceToRelease->Release();
		pInterfaceToRelease = NULL;
	}
}

enum ScreenLayout {
	// TODO: ���kLayoutOfUnknown��ת��
	kLayoutOfUnknown = -1,
	kLayoutOf1x1 = 0,
	kLayoutOf2x2 = 1,
	kLayoutOf3x3 = 2,
	kLayoutOf1plus5 = 3,
	kLayoutOfAuto = 11,
	kLayoutOfDocument = 10,
	kLayoutOfTop1x2 = 12,
	kLayoutOf4x4 = 13,
	kLayoutOfAirplay = 14,
};