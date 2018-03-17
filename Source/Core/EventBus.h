#pragma once
#include <string>
#include <unordered_map>
class Events {
public:
    const std::string NotePressed = "NotePressed";
};


class EventBus {
public:
    EventBus(){}
    Events events;
    std::unordered_map<std::string, int> eventNameToCallbacksMap;
    template<typename TEventData>
    void trigger(TEventData data){
      printf("eventBus trigger called \n");
    }
private:

};

//global instance
extern EventBus eventBus;
