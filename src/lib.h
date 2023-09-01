#ifndef LIB_H
#define LIB_H

#include <string>
#include <iostream>
#include <functional>
#include <scapix/bridge/object.h>
#include <future>

namespace demo
{

    class device : public scapix::bridge::object<device>

    {
    public:
        device() noexcept {};

        void initialize(std::function<std::vector<uint8_t>(void)> load_cfg_cb)
        {

            auto handle = std::async(std::launch::async, [load_cfg_cb]
                                     {
                                         try
                                         {
                                             std::cout << "Loading configuration" << std::endl;
                                             auto config = load_cfg_cb();
                                             std::cout << "Configuration size:" << config.size() << std::endl;
                                         }
                                         catch (const std::exception &e)
                                         {
                                             std::cerr << " Exception " << e.what() << std::endl;
                                         }
                                         return true;
                                     });
            handle.get();

            std::cout << "Configuration loaded" << std::endl;
        }

    private:
    };

} // namespace demo

#endif // LIB_H
