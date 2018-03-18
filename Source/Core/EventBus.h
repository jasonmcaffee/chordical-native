#pragma once
#include <string>
#include <unordered_map>
#include <vector>
//template<typename TEventData>
//using EventCallback = std::function<void(TEventData)>;
//typedef void (EventCallback)();

class EventData{
    virtual void nothing(){}
};
class NotePressedEventData : public EventData{
public:
    NotePressedEventData(std::string notePressed){
      this->notePressed = notePressed;
    }
    std::string notePressed;
};

class Events {
public:
    const std::string NotePressed = "NotePressed";
};


class EventBus {
public:
    EventBus(){}
    Events events;

//    template<typename TEventData>
//    std::unordered_map<std::string, std::vector<std::function<void(TEventData)>> > eventNameToCallbacksMap;
//    template<typename TEventData>
//    std::unordered_map< std::string, std::vector<EventCallback<void*>> > eventNameToCallbacksMap;
    std::unordered_map< std::string, std::vector<std::function<void(EventData*)>> > eventNameToCallbacksMap;
//    template<typename TEventData>
    void trigger(std::string eventName, EventData* data){
      printf("eventBus trigger called \n");
      std::vector<std::function<void(EventData*)>> callbacks = this->eventNameToCallbacksMap[eventName];
      for(auto const& cb: callbacks) {
        cb(data);
      }
    }

    void registerCallback(std::string eventName, std::function<void(EventData*)> callback){
      this->eventNameToCallbacksMap[eventName].push_back(callback);
    }
private:

};

//global instance
extern EventBus eventBus;
