#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    const char* disk_device = "/dev/nvme0n1";
    const int sector_size = 512;
    char mbr[sector_size];

    // Open the disk device for reading
    std::ifstream disk(disk_device, std::ios::binary);
    if (!disk) {
        std::cerr << "Failed to open disk device: " << disk_device << std::endl;
        return 1;
    }

    // Read the first sector (MBR) from the disk
    disk.read(mbr, sector_size);
    if (!disk) {
        std::cerr << "Failed to read MBR from disk" << std::endl;
        return 1;
    }

    // Process the MBR data
    // You can interpret and analyze the MBR data here
    // For example, you can print out the first few bytes
    std::cout << "MBR Data:" << std::endl;
    for (int i = 0; i < 64; ++i) {
        std::cout << std::hex << (int)mbr[i] << " ";
    }
    std::cout << std::endl;

    // Close the disk device
    disk.close();

    return 0;
}
