//
//  PSCSpringKitManager.m
//  PSCSpringKitManager
//
//  Created by Manfred Scheiner on 15.02.13.
//  Copyright (c) 2013 PocketScience GmbH. All rights reserved.
//

#import "PSCSpringKitManager.h"
#import "SurveySpring.h"

@interface PSCSpringKitManager ()

@property (nonatomic, strong) Spring *spring;
@property (nonatomic, assign) BOOL survey;
@property (nonatomic, strong) NSArray *hitTestClasses;

@end

@implementation PSCSpringKitManager

- (id)initWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path hitTestClasses:(NSArray *)hitTestClasses survey:(BOOL)survey {
    self = [super init];
    if (self != nil) {
        _survey = survey;
        if (survey) {
            _spring = [[SurveySpring alloc] initWithSiteAndApplication:site application:application];
        } else {
            _spring = [[Spring alloc] initWithSiteAndApplication:site application:application];
        }
        _path = path;
        _hitTestClasses = hitTestClasses;
        [self performCount];
    }
    return self;
}

- (void)performCount {
    [self performCountWithPath:self.path];
}

- (void)performCountWithPath:(NSString *)path {
    if (path) {
        //dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
        NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithObject:path forKey:@"cp"];
        [self.spring commit:dict];
        //});
    }
}

- (BOOL)containsHitTestClass:(Class)hitTestClass {
    for (Class class in self.hitTestClasses) {
        if ([hitTestClass isSubclassOfClass:class]) {
            return YES;
        }
    }
    return NO;
}

- (void)debugMode:(BOOL)debug {
    self.spring.debug = debug;
    self.spring.offlineMode = debug;
}

- (void)trackingActive:(BOOL)active {
    self.spring.tracking = active;
}

////////////////////////////////////////////////////////////////////////
#pragma mark - Singleton definitons
////////////////////////////////////////////////////////////////////////

static PSCSpringKitManager *sharedSpringKitManager = nil;

+ (PSCSpringKitManager *)createSharedSpringKitManagerWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path hitTestClasses:(NSArray *)hitTestClasses survey:(BOOL)survey {
    sharedSpringKitManager = [[PSCSpringKitManager alloc] initWithSite:site application:application path:path hitTestClasses:hitTestClasses survey:survey];
    return [PSCSpringKitManager sharedSpringKitManager];
}

+ (PSCSpringKitManager *)createSharedSpringKitManagerWithSite:(NSString *)site application:(NSString *)application path:(NSString *)path hitTestClasses:(NSArray *)hitTestClasses {
    return [self createSharedSpringKitManagerWithSite:site application:application path:path hitTestClasses:hitTestClasses survey:NO];
}

+ (PSCSpringKitManager *)sharedSpringKitManager {
    return sharedSpringKitManager;
}

+ (void)performCount {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        [[PSCSpringKitManager sharedSpringKitManager] performCount];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
}

+ (void)performCountWithPath:(NSString *)path {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        [[PSCSpringKitManager sharedSpringKitManager] performCountWithPath:path];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
}

+ (BOOL)containsHitTestClass:(Class)hitTestClass {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        return [[PSCSpringKitManager sharedSpringKitManager] containsHitTestClass:hitTestClass];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
    return NO;
}

+ (void)debugMode:(BOOL)debug {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        [[PSCSpringKitManager sharedSpringKitManager] debugMode:debug];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
}

+ (void)trackingActive:(BOOL)isTrackingActive {
    if ([PSCSpringKitManager sharedSpringKitManager] != nil) {
        [[PSCSpringKitManager sharedSpringKitManager] trackingActive:isTrackingActive];
    }
    else {
        NSLog(@"Shared PSCSpringKitManager not created yet!");
    }
}

@end
