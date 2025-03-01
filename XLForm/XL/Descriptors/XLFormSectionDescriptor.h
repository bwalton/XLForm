//
//  XLFormSectionDescriptor.h
//  XLForm ( https://github.com/xmartlabs/XLForm )
//
//  Copyright (c) 2015 Xmartlabs ( http://xmartlabs.com )
//
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "XLFormRowDescriptor.h"
#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, XLFormSectionOptions) {
    XLFormSectionOptionNone        = 0,
    XLFormSectionOptionCanInsert   = 1 << 0,
    XLFormSectionOptionCanDelete   = 1 << 1,
    XLFormSectionOptionCanReorder  = 1 << 2
};

typedef NS_ENUM(NSUInteger, XLFormSectionInsertMode) {
    XLFormSectionInsertModeLastRow = 0,
    XLFormSectionInsertModeButton = 2
};

@class XLFormDescriptor;

@interface XLFormSectionDescriptor : NSObject

@property (nonatomic, nullable, copy) NSString * title;
@property (nonatomic, nullable, copy) NSString * footerTitle;
@property (nonatomic, readonly, nonnull, strong) NSMutableArray * formRows;

@property (nonatomic, readonly, assign) XLFormSectionInsertMode sectionInsertMode;
@property (nonatomic, readonly, assign) XLFormSectionOptions sectionOptions;
@property (nonatomic, nullable, strong) XLFormRowDescriptor * multivaluedRowTemplate;
@property (nonatomic, readonly, nullable, strong) XLFormRowDescriptor * multivaluedAddButton;
@property (nonatomic, nullable, copy) NSString * multivaluedTag;

@property (nonatomic, weak, null_unspecified) XLFormDescriptor * formDescriptor;

@property (nonatomic, nonnull, strong) id hidden;
-(BOOL)isHidden;


// Temp fix for RM issues
@property (nonatomic, nonnull, strong) id zebra;

+(nonnull instancetype)formSection;
+(nonnull instancetype)formSectionWithTitle:(nullable NSString *)title;
+(nonnull instancetype)formSectionWithTitle:(nullable NSString *)title multivaluedSection:(BOOL)multivaluedSection DEPRECATED_ATTRIBUTE DEPRECATED_MSG_ATTRIBUTE("Use formSectionWithTitle:sectionType: instead");
+(nonnull instancetype)formSectionWithTitle:(nullable NSString *)title sectionOptions:(XLFormSectionOptions)sectionOptions;
+(nonnull instancetype)formSectionWithTitle:(nullable NSString *)title sectionOptions:(XLFormSectionOptions)sectionOptions sectionInsertMode:(XLFormSectionInsertMode)sectionInsertMode;

-(BOOL)isMultivaluedSection;
-(void)addFormRow:(nonnull XLFormRowDescriptor *)formRow;
-(void)addFormRow:(nonnull XLFormRowDescriptor *)formRow afterRow:(nonnull XLFormRowDescriptor *)afterRow;
-(void)addFormRow:(nonnull XLFormRowDescriptor *)formRow beforeRow:(nonnull XLFormRowDescriptor *)beforeRow;
-(void)removeFormRowAtIndex:(NSUInteger)index;
-(void)removeFormRow:(nonnull XLFormRowDescriptor *)formRow;
-(void)moveRowAtIndexPath:(nonnull NSIndexPath *)sourceIndex toIndexPath:(nonnull NSIndexPath *)destinationIndex;

@end
