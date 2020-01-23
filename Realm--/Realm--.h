//
//  Realm--.h
//  Realm--
//
//  Created by MeterWhite on 2020/1/21.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#ifndef Realm___h
#define Realm___h

#import "RLLWriting.h"
#import "RLLUpdate.h"
#import "RLLDelete.h"
#import "RLLAdd.h"

#pragma mark - Commit pool

/**
 * These macro definitions ensure commits transaction when leaving this scope.
 * Variable 'realm' can be used in each realm pool.
 * @realm_writing_pool({
 *     ...
 * });
 * @realm_update_pool({
 *     ...
 *     Update = ...
 * });
 * @realm_delete_pool({
 *     ...
 *     Delete = ...
 * });
 * @realm_add_pool({
 *     ...
 *     Add = ...
 * });
 */
#define realm_writing_pool(...) \
autoreleasepool {           \
    @realm_writing_scope    \
    __VA_ARGS__             \
}

#define realm_update_pool(...)  \
autoreleasepool {           \
    @realm_update_scope     \
    __VA_ARGS__             \
}

#define realm_delete_pool(...)  \
autoreleasepool {           \
    @realm_delete_scope     \
    __VA_ARGS__             \
}

#define realm_add_pool(...) \
autoreleasepool {           \
    @realm_add_scope        \
    __VA_ARGS__             \
}

#pragma mark - Commit scope
/**
 * Effective in any scope.Realm transaction will be committed when autoreleapool is released.Usually at the end of a loop of the current runloop.
 * ... {
 *    @realm_writing_scope
 *    ...
 * }
 */
#define realm_writing_scope \
autoreleasepool{}           \
RLMRealm *realm __attribute__((unused)) = [RLLWriting scope];

#define realm_update_scope  \
autoreleasepool{}           \
id Update;                  \
RLMRealm *realm __attribute__((unused)) = [RLLUpdate scopeWithPointer:&Update];

#define realm_add_scope \
autoreleasepool{}       \
id Add;                 \
RLMRealm *realm __attribute__((unused)) = [RLLAdd scopeWithPointer:&Add];

#define realm_delete_scope  \
autoreleasepool{}           \
id Delete;                  \
RLMRealm *realm __attribute__((unused)) = [RLLDelete scopeWithPointer:&Delete];

#pragma mark - Change realm of current scope
/**
 * Switch realm in current scope.It will try to commit the previous transaction before.
 */
#define realm_switch(...)   \
autoreleasepool{}           \
[(RLLWriting *)realm switchRealm:(__VA_ARGS__)];
#endif

#pragma mark -
#define realm_without_notifying(...)    \
autoreleasepool{}                       \
[(RLLWriting *)realm setWithoutNotifying:(__VA_ARGS__)];
