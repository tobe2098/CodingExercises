#include "compareVersions.hpp"

int compareVersion(std::string version1, std::string version2) {
    int rev1{}, rev2{}, ptr1{}, ptr2{};
    std::string crev1, crev2;
    while (rev1 != -1 || rev2 != -1) {
        if (!crev1.empty()) {
            int r1{ std::stoi(crev1) }, r2{ std::stoi(crev2) };
            if (r1 < r2) {
                return -1;
            }
            else if (r1 > r2) {
                return 1;
            }
        }
        //Next revision
        crev1.clear();
        crev2.clear();
        while (ptr1 < version1.length() && version1[ptr1] != '.') {
            crev1.push_back(version1[ptr1]);
            ptr1++;
        }
        if (ptr1 >= version1.length() && crev1.empty()) {
            rev1 = -1;
            crev1 = "0";
        }
        else {
            ptr1++;
            rev1++;
        }
        while (ptr2 < version2.length() && version2[ptr2] != '.') {
            crev2.push_back(version2[ptr2]);
            ptr2++;
        }
        if (ptr2 >= version2.length() && crev2.empty()) {
            rev2 = -1;
            crev2 = "0";
        }
        else {
            ptr2++;
            rev2++;
        }
    }
    return 0;
}