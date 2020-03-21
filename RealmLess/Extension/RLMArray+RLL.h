//
//  RLMArray+RLL.h
//  Realm--
//
//  Created by MeterWhite on 2020/1/29.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#import <Realm/Realm.h>

@interface RLMArray (RLL)
@property (nonnull,nonatomic,readonly,copy) NSMutableArray<RLMArray *> *rll_asArray;
@property (nonnull,nonatomic,readonly,copy) RLMObject *rll_asObject;
@end

