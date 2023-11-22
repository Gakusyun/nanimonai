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
class SecondPage extends ViewPU {
    constructor(parent, params, __localStorage, elmtId = -1) {
        super(parent, __localStorage, elmtId);
        this.__message = new ObservedPropertySimplePU(CommonConstants.SECOND_MESSAGE, this, "message");
        this.__src = new ObservedPropertySimplePU(router.getParams()[CommonConstants.SECOND_SRC_PARAM], this, "src");
        this.setInitiallyProvidedValue(params);
    }
    setInitiallyProvidedValue(params) {
        if (params.message !== undefined) {
            this.message = params.message;
        }
        if (params.src !== undefined) {
            this.src = params.src;
        }
    }
    updateStateVars(params) {
    }
    purgeVariableDependenciesOnElmtId(rmElmtId) {
        this.__message.purgeDependencyOnElmtId(rmElmtId);
        this.__src.purgeDependencyOnElmtId(rmElmtId);
    }
    aboutToBeDeleted() {
        this.__message.aboutToBeDeleted();
        this.__src.aboutToBeDeleted();
        SubscriberManager.Get().delete(this.id__());
        this.aboutToBeDeletedInternal();
    }
    get message() {
        return this.__message.get();
    }
    set message(newValue) {
        this.__message.set(newValue);
    }
    get src() {
        return this.__src.get();
    }
    set src(newValue) {
        this.__src.set(newValue);
    }
    initialRender() {
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Row.create();
            Row.debugLine("pages/SecondPage.ets(29:5)");
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
            Column.debugLine("pages/SecondPage.ets(30:7)");
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
            Text.debugLine("pages/SecondPage.ets(31:9)");
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
            Text.create(this.src);
            Text.debugLine("pages/SecondPage.ets(34:9)");
            Text.fontSize(CommonConstants.PARAMS_FONT_SIZE);
            Text.opacity(CommonConstants.PARAMS_OPACITY);
            if (!isInitialRender) {
                Text.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Text.pop();
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Blank.create();
            Blank.debugLine("pages/SecondPage.ets(37:9)");
            if (!isInitialRender) {
                Blank.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Blank.pop();
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Button.createWithLabel({ "id": 16777221, "type": 10003, params: [], "bundleName": "com.example.pagesrouter", "moduleName": "entry" });
            Button.debugLine("pages/SecondPage.ets(38:9)");
            Button.fontSize(CommonConstants.BUTTON_FONT_SIZE);
            Button.width(CommonConstants.BUTTON_WIDTH);
            Button.height(CommonConstants.BUTTON_HEIGHT);
            Button.backgroundColor({ "id": 16777225, "type": 10001, params: [], "bundleName": "com.example.pagesrouter", "moduleName": "entry" });
            Button.onClick(() => {
                router.back();
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
loadDocument(new SecondPage(undefined, {}));
ViewStackProcessor.StopGetAccessRecording();
//# sourceMappingURL=SecondPage.js.map