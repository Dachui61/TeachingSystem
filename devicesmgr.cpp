#include "devicesmgr.h"

DevicesMgr::DevicesMgr() {

    //构造初始化学生和主设备

    //从配置文件里读取设备信息


    //暂时模拟初始化两台设备
    // CameraView *cameraView = new CameraView("10.16.41.20", 8001, "admin", "cqupt2210", 1, 0, 0, 1);
    main_dev = Device("10.16.26.167",8000, "admin","abcd1234");

    devices.push_back({"10.16.41.20", 8001, "admin", "cqupt2210", 1, 0, 0, 1});
    devices.push_back({"10.16.41.20", 8001, "admin", "cqupt2210", 1, 0, 0, 1});
    devices.push_back({"10.16.41.20", 8001, "admin", "cqupt2210", 1, 0, 0, 1});
    devices.push_back({"10.16.41.20", 8001, "admin", "cqupt2210", 1, 0, 0, 1});
    devices.push_back({"10.16.41.20", 8001, "admin", "cqupt2210", 1, 0, 0, 1});


}
DevicesMgr::~DevicesMgr() {
    // 析构函数的实现，如果有必要进行清理工作
}

void DevicesMgr::addDevice(const Device& device) {
    devices.push_back(device);
}

const std::vector<Device>& DevicesMgr::getDevices() const {
    return devices;
}

void DevicesMgr::setMainDevice(const Device& device) {
    main_dev = device;
}

const Device& DevicesMgr::getMainDevice() const {
    return main_dev;
}
