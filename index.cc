#include <node.h>
#include <v8.h>

#import "notifications.h"

using namespace v8;

void initializeCallbackFunc(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    Local<Function> callback = Local<Function>::Cast(args[0]);
    initializeCallback(callback);
}

void showNotificationFunc(const v8::FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    if (args[0]->IsString()) {
        Local<String> obj = args[0]->ToString();
        showNotification(obj);
    }
}

void hideNotificationFunc(const v8::FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    hideNotification();
}

void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "initializeCallback", initializeCallbackFunc);
    NODE_SET_METHOD(exports, "showNotification", showNotificationFunc);
    NODE_SET_METHOD(exports, "hideNotification", hideNotificationFunc);
}

NODE_MODULE(hello, Init)
