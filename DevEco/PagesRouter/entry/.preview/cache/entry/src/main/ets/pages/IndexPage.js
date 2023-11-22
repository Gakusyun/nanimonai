/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
import router from '@ohos:router';
import CommonConstants from '@bundle:com.example.pagesrouter/entry/ets/common/constants/CommonConstants';
import Logger from '@bundle:com.example.pagesrouter/entry/ets/common/utils/Logger';
const TAG = '[IndexPage]';
class IndexPage extends ViewPU {
    constructor(parent, params, __localStorage, elmtId = -1) {
        super(parent, __localStorage, elmtId);
        this.__message = new ObservedPropertySimplePU(CommonConstants.INDEX_MESSAGE, this, "message");
        this.setInitiallyProvidedValue(params);
    }
    setInitiallyProvidedValue(params) {
        if (params.message !== undefined) {
            this.message = params.message;
        }
    }
    updateStateVars(params) {
    }
    purgeVariableDependenciesOnElmtId(rmElmtId) {
        this.__message.purgeDependencyOnElmtId(rmElmtId);
    }
    aboutToBeDeleted() {
        this.__message.aboutToBeDeleted();
        SubscriberManager.Get().delete(this.id__());
        this.aboutToBeDeletedInternal();
    }
    get message() {
        return this.__message.get();
    }
    set message(newValue) {
        this.__message.set(newValue);
    }
    initialRender() {
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Row.create();
            Row.debugLine("pages/IndexPage.ets(31:5)");
            Row.height(CommonConstants.FULL_HEIGHT);
            Row.backgroundColor({ "id": 16777226, "type": 10001, params: [], "bundleName": "com.example.pagesrouter", "moduleName": "entry" });
            if (!isInitialRender) {
                Row.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Column.create();
            Column.debugLine("pages/IndexPage.ets(32:7)");
            Column.width(CommonConstants.FULL_WIDTH);
            Column.height(CommonConstants.LAYOUT_HEIGHT);
            if (!isInitialRender) {
                Column.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Text.create(this.message);
            Text.debugLine("pages/IndexPage.ets(33:9)");
            Text.fontSize(CommonConstants.FONT_SIZE);
            Text.fontWeight(FontWeight.Bold);
            if (!isInitialRender) {
                Text.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Text.pop();
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Blank.create();
            Blank.debugLine("pages/IndexPage.ets(36:9)");
            if (!isInitialRender) {
                Blank.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Blank.pop();
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Button.createWithLabel({ "id": 16777223, "type": 10003, params: [], "bundleName": "com.example.pagesrouter", "moduleName": "entry" });
            Button.debugLine("pages/IndexPage.ets(37:9)");
            Button.fontSize(CommonConstants.BUTTON_FONT_SIZE);
            Button.width(CommonConstants.BUTTON_WIDTH);
            Button.height(CommonConstants.BUTTON_HEIGHT);
            Button.backgroundColor({ "id": 16777225, "type": 10001, params: [], "bundleName": "com.example.pagesrouter", "moduleName": "entry" });
            Button.onClick(() => {
                router.pushUrl({
                    url: CommonConstants.SECOND_URL,
                    params: {
                        src: CommonConstants.SECOND_SRC_MSG
                    }
                }).catch((error) => {
                    Logger.info(TAG, 'IndexPage push error' + JSON.stringify(error));
                });
            });
            if (!isInitialRender) {
                Button.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Button.pop();
        Column.pop();
        Row.pop();
    }
    rerender() {
        this.updateDirtyElements();
    }
}
ViewStackProcessor.StartGetAccessRecordingFor(ViewStackProcessor.AllocateNewElmetIdForNextComponent());
loadDocument(new IndexPage(undefined, {}));
ViewStackProcessor.StopGetAccessRecording();
//# sourceMappingURL=IndexPage.js.map