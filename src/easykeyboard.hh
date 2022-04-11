#pragma once

#include <functional>
#include <string>
#include <unordered_map>

namespace keyboard {

typedef std::function<void(void *event, void *data)> keybind_callback;

typedef std::function<void(void *data)> keybind_destructor;

struct KeyBind {
  keybind_callback callback;
  keybind_destructor destroy_data;
  void *data;
  KeyBind(keybind_callback, keybind_destructor, void * = NULL);
};

// TODO, reuse KeyBind objects?, delete all
class KeyMap {
 private:
  std::unordered_map<std::string, KeyBind *> keymap;

 public:
  void set(std::string key, KeyBind bind) {
    // if key already set, delete previous binding
    destroy(key);
    keymap[key] = new KeyBind(bind);
  }

  void callback(std::string key, void *event) {
    if (auto pair = keymap.find(key); pair != keymap.end()) {
      auto bind = pair->second;
      bind->callback(event, bind->data);
    }
  }

  void destroy(std::string key) {
    if (auto pair = keymap.find(key); pair != keymap.end()) {
      auto bind = pair->second;
      bind->destroy_data(bind->data);
      delete bind;
    }
  }
};
};  // namespace keyboard
