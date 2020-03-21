//
//  RLMArray+RLL.m
//  Realm--
//
//  Created by MeterWhite on 2020/1/29.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#import "RLMArray+RLL.h"

@implementation RLMArray (RLL)
- (NSMutableArray<RLMArray *> *)rll_asArray {
    NSMutableArray *ret = [NSMutableArray array];
    for (RLMObject *item in self) {
        [ret addObject:item];
    }
    return ret;
}

- (RLMObject *)rll_asObject {
    if(self.count != 1) return nil;
    return self.firstObject;
}
@end
