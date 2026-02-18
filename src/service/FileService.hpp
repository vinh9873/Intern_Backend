#pragma once

#include "oatpp/core/Types.hpp"

class FileService {
public:
  
  oatpp::Fields<oatpp::String> uploadFile() {
    auto res = oatpp::Fields<oatpp::String>::createShared();
    res["message"] = "File Uploaded!";
    return res;
  }

};
