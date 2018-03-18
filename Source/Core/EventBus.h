#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::string;
using std::vector;
using std::function;

class EventData{
    virtual void nothing(){}
};
class NotePressedEventData : public EventData{
public:
    NotePressedEventData(string notePressed){
      this->notePressed = notePressed;
    }
    string notePressed;
};

class Events {
public:
    const string NotePressed = "NotePressed";
};


class EventBus {
public:
    EventBus(){}
    Events events;

    unordered_map<string, vector<function<void(EventData*)>> > eventNameToCallbacksMap;

    void trigger(string eventName, EventData* data){
      printf("eventBus trigger called \n");
      vector<function<void(EventData*)>> callbacks = this->eventNameToCallbacksMap[eventName];
      for(auto const& cb: callbacks) {
        cb(data);
      }
    }

    void registerCallback(string eventName, function<void(EventData*)> callback){
      this->eventNameToCallbacksMap[eventName].push_back(callback);
    }
};

//global instance
extern EventBus eventBus;
