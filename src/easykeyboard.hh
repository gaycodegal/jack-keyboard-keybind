#pragma once

#include <functional>
#include <string>
#include <unordered_map>

namespace keymap {
// see google styleguide on namespaces
// helps avoid conflicts, but you can just use keymap::KeyMap if you don't have
// conflicts
inline namespace easy {

typedef std::function<void(void *event, void *data)> keybind_callback;

typedef std::function<void(void *data)> keybind_destructor;

struct KeyBind {
  keybind_callback callback;
  keybind_destructor destroy_data;
  void *data;
  KeyBind(keybind_callback callback, keybind_destructor destroy_data,
          void *data = NULL)
      : callback(callback), destroy_data(destroy_data), data(data){};
};

// TODO, reuse KeyBind objects?, delete all
class KeyMap {
 private:
  std::unordered_map<std::string, KeyBind *> keymap;

  void destroy(std::string key) {
    if (auto pair = keymap.find(key); pair != keymap.end()) {
      destroy(&(*pair));
    }
  }

  void destroy(std::pair<const std::string, KeyBind *> *pair) {
    auto bind = pair->second;
    bind->destroy_data(bind->data);
    delete bind;
  }

 public:
  ~KeyMap() {
    for (auto i : keymap) {
      destroy(&i);
    }
  };

  void set(std::string key, KeyBind bind) {
    // if key already set, delete previous binding
    destroy(key);
    keymap[key] = new KeyBind(bind);
  }

  bool callback(std::string key, void *event) {
    if (auto pair = keymap.find(key); pair != keymap.end()) {
      auto bind = pair->second;
      bind->callback(event, bind->data);
      return true;
    }
    return false;
  }
};

};  // namespace easy
};  // namespace keymap
