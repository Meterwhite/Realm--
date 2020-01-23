//
//  RLLAdd.m
//  Demo
//
//  Created by MeterWhite on 2020/1/22.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#import "RLLAdd.h"

@implementation RLLAdd
- (void)dealloc {
    if([_realm inWriteTransaction]) {
        id obj = *_value;
        if(obj){
            if([obj conformsToProtocol:@protocol(NSFastEnumeration)]){
                [_realm addObjects:obj];
            } else {
                [_realm addObject:obj];
            }
        }
        if(_withoutNotifying == nil) {
            [_realm commitWriteTransaction];
        } else {
            [_realm commitWriteTransactionWithoutNotifying:_withoutNotifying error:nil];
        }
#ifdef DEBUG
        NSLog(@"realm-- : committed.");
#endif
    }
    _value = nil;
    _realm = nil;
}
@end
