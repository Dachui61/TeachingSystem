#ifndef DEVICESMGR_H
#define DEVICESMGR_H
#include <QObject>
#include "singleton.h"
#include <QString>

struct Device {
    QString ip;                // 设备IP地址
    int port;                  // 设备端口号
    QString username;          // 登录用户名
    QString password;          // 登录密码
    int lChannel;              // 通道号
    int dwStreamType;          // 主码流类型
    int dwLinkMode;            // 链接模式
    bool bBlocked;             // 是否阻塞方式

    // 构造函数，方便初始化结构体
    Device(QString ip, int port, QString username, QString password,
           int lChannel = 1, int dwStreamType = 0, int dwLinkMode = 0, bool bBlocked = true)
        : ip(ip), port(port), username(username), password(password),
        lChannel(lChannel), dwStreamType(dwStreamType), dwLinkMode(dwLinkMode), bBlocked(bBlocked) {}

    Device()
        : ip(""), port(0), username("admin"), password("abcd1234"),
        lChannel(1), dwStreamType(0), dwLinkMode(0), bBlocked(1) {}
};

class DevicesMgr:public QObject, public Singleton<DevicesMgr>,public std::enable_shared_from_this<DevicesMgr>
{
    Q_OBJECT

public:
    ~DevicesMgr();

    // 添加设备到学生设备列表
    void addDevice(const Device& device);

    // 获取学生设备列表
    const std::vector<Device>& getDevices() const;

    // 设置主设备（老师设备）
    void setMainDevice(const Device& device);

    // 获取主设备（老师设备）
    const Device& getMainDevice() const;

private:
    friend class Singleton<DevicesMgr>;
    DevicesMgr();

private:
    //维护一个学生设备的列表
    std::vector<Device> devices;
    //维护一个老师设备的列表
    Device main_dev;
};

#endif // DEVICESMGR_H
