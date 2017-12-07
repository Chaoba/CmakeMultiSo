//
// Created by Li Yanshun on 2017/6/6.
//

#include "../include/Layer2.h"
#include <memory>
#include <dlfcn.h>
#include <Layer1.h>

std::string get_self_dir() {
    static const char *SELF_NAME = "/liblayer2.so";
    static const size_t SELF_NAME_LEN = strlen(SELF_NAME);
    FILE *fmap = fopen("/proc/self/maps", "r");
    if (!fmap) {
        LOG_E("failed to open maps");
        return {};
    }
    std::unique_ptr<FILE, int (*)(FILE *)> fmap_close{fmap, ::fclose};
    char linebuf[512];
    while (fgets(linebuf, sizeof(linebuf), fmap)) {
        uintptr_t begin, end;
        char perm[10], offset[20], dev[10], inode[20], path_mem[256], *path;
        int nr = sscanf(linebuf, "%zx-%zx %s %s %s %s %s", &begin, &end, perm,
                        offset, dev, inode, path_mem);
        if (nr == 6) {
            path = nullptr;
        } else {
            if (nr != 7) {
                LOG_E("failed to parse map line: %s", linebuf);
                return {};
            }
            path = path_mem;
        }
        if (path) {
            auto len = strlen(path);
            auto last_dir_end = path + len - SELF_NAME_LEN;
            if (!strcmp(last_dir_end, SELF_NAME)) {
                // last_dir_end now points to the '/'; we modify its next
                // character to truncate the string
                last_dir_end[1] = 0;
                return path;
            }
        }
    }
    LOG_E("can not find path of %s", SELF_NAME + 1);
    return {};
}

NET_API_FUNCTIONS_TYPE_LAYER1 *client_layer1;

std::string get_response_layer2() {
    LOG_E("layer2 get response");
//    const std::string &layer1 = net_client_layer1.getResponse();
    const std::string &layer1 = client_layer1->getRequest();
    return "layer2:" + layer1;
}

std::string get_request_layer2() {
    LOG_E("layer2 get request");
//    const std::string &layer1 = net_client_layer1.getRequest();
    const std::string &layer1 = client_layer1->getRequest();
    return "layer2:" + layer1;
}

void init() {
    static std::string self_dir = get_self_dir();
    if (self_dir.empty())
        return;
    std::string path{self_dir};
    path.append("liblayer1.so");
    LOG_E("dlopen %s:", path.c_str());
    void *handle = dlopen(path.c_str(), RTLD_LAZY | RTLD_LOCAL);
    if (!handle) {
        return;
    }
    auto sym = dlsym(handle, "net_client_layer1");

    if (!sym) {
        return;
    }
    client_layer1 = reinterpret_cast<NET_API_FUNCTIONS_TYPE_LAYER1 *>(sym);

}

__attribute__ ((visibility ("default"))) NET_API_FUNCTIONS_TYPE_LAYER2 net_client_layer2 = {
        get_response_layer2,
        get_request_layer2,
        init,
};
