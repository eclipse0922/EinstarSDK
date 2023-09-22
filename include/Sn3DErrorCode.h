#ifndef SN3DERRORCODE_H
#define SN3DERRORCODE_H

typedef int SN3DERROR;

#define  EC_SUCCESS										0x00000000 // �ɹ�								No error
#define  EC_NOTINITIALIZED								0x00000001  // û�г�ʼ��						No initialization
#define  EC_INITIALIZEFIAILZED							0x00000002  // ��ʼ��ʧ��						Initialization failed.
#define  EC_AlREADYINITIALIZED							0x00000003  // �ظ���ʼ��						Initialization repeat.
#define  EC_SAVEFAILED_TYPEERROR						0x00000004  // ����ʧ�ܣ���ʽ����				Format error��failed to save files.
#define  EC_CHECKDEVICEFAILED_PLENOTRIGHT				0x00000005  // �����豸ʧ�ܣ�ple����ȷ			PLE error, failed to connect device.
#define  EC_CHECKDEVICEFAILED_NODEVICEFOUND				0x00000006  // �����豸ʧ�ܣ�δ�����豸			Device no found, connection failed.
#define  EC_OPENORCREATSLNFAILED						0x00000007   // ������򿪹���ʧ��				Failed to create or open project.
#define  EC_ENTERSCANFAILED								0x00000008        // ����ɨ��ʧ��				Failed to enter scan mode.
#define  EC_SCANFAILED									0x00000009        // ɨ����ʧ��					Scanning failed.
#define  EC_ENDSCANFAILED								0x0000000A        // ����ʧ��					Generating failed.
#define  EC_MESHFAILED									0x0000000B        // ����ʧ��					Meshing failed.
#define  EC_EXITSCANFAILED								0x0000000C        // �˳�ɨ��					Quitting scan mode failed.
#define  EC_CANCELSCANFAILED							0x0000000D        // ȡ��ɨ��					Canceling scan failed.
#define  EC_SAVEFAILED									0x0000000E        // ����ʧ��					Saving failed.
#define  EC_CREATNEWPROJECTFAILED						0x00000010        // �½�����ʧ��				New project failed.
#define  EC_WORKRANGE									0x00000011	//�������뷶Χ������Ҫ��			The working range dose not meet the requirements

#define  EC_PROCESSERROR								0x10000000   // ���̵��ô���					Process call error
#endif // SN3DERRORCODE_H
