#import <Foundation/Foundation.h>

@interface Person : NSObject {
    @private char *name;
}
@property (readwrite, assign) char *name;
- (void)sayHello;
@end

@implementation Person
@synthesize name;

- (void)sayHello {
    printf("Hello, my name is %s!\n", [self name]);
}

- (NSString *)description {
	NSString *sz = [NSString stringWithFormat:@"Name: %s", self.name];
	return sz;
}

@end

int main() {
    Person *brad = [Person new];
    brad.name = "Brad Cox";
    [brad sayHello];

    Person *tom = [Person new];
    tom.name = "Tom Love";
    [tom sayHello];
}