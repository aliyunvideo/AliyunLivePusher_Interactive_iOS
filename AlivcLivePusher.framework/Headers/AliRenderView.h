//
//  AliRenderView.h
//  AliRTCSdk
//
//  Created by lyz on 2021/2/26.
//  Copyright © 2021 mt. All rights reserved.
//

#ifndef AliRenderView_h
#define AliRenderView_h

#import <UIKit/UIKit.h>
#import "engine_define.h"

ALI_RTC_API @interface AliRenderView : UIView

@property (nonatomic, assign, readonly) NSUInteger renderId;
@property (nonatomic, assign, readonly) int renderWidth;
@property (nonatomic, assign, readonly) int renderHeight;
@property (nonatomic, assign, readonly) BOOL enable_optimization;

- (void *)getEngineDisplayView;

@end

#endif /* AliRenderView_h */
