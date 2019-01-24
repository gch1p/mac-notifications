#import <node.h>
#import <v8.h>

using namespace v8;

void initializeCallback(Local<Function> replyCallback);
void showNotification(Local<String> object);
void hideNotification();
