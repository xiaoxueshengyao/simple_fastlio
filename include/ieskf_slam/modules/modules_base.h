/**
 * @author: yao
 * @lastEditTime: 2025年3月18日18:31:01
 */

#pragma once 

#include <string>
#include <iostream>
#include <yaml-cpp/yaml.h>

namespace IESKFLio
{
class ModuleBase
{
    private:
        YAML::Node config_node;
        std::string name;
    
    protected:
        // 构造函数用于加载参数文件
        ModuleBase(const std::string& config_path, const std::string& prefix, const std::string* module_name="default")
        {
            name = module_name;
            if(config_path != "")
            {
                try
                {
                    config_node = YAML::LoadFile(config_path);
                }
                catch (YAML::Exception& e)
                {
                    std::cout<<e.msg<<std::endl;
                }

                if(prefix !="" && config_node[prefix])
                    config_node = config_node[prefix];
            }

        }


        // 使用模版读取参数
        template<typename T>
        void readParam(const std::string& key, T& val, T default_val)
        {
            if(config_node[key])
            {
                val = config_node[key].as<T>();
            }
            else
            {
                val = default_val;
            }
        }
};
} 