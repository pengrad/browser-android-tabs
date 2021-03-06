// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * A test version of LocalDataBrowserProxy. Provides helper methods
 * for allowing tests to know when a method was called, as well as
 * specifying mock responses.
 *
 * @implements {settings.LocalDataBrowserProxy}
 */
class TestLocalDataBrowserProxy extends TestBrowserProxy {
  constructor() {
    super([
      'getDisplayList',
      'removeAll',
      'removeShownItems',
      'removeItem',
      'getCookieDetails',
      'reloadCookies',
      'removeCookie',
    ]);

    /** @private {?CookieList} */
    this.cookieDetails_ = null;

    /** @private {Array<!CookieList>} */
    this.cookieList_ = [];
  }

  /**
   * Test-only helper.
   * @param {!CookieList} cookieList
   */
  setCookieDetails(cookieList) {
    this.cookieDetails_ = cookieList;
  }

  /**
   * Test-only helper.
   * @param {!CookieList} cookieList
   */
  setCookieList(cookieList) {
    this.cookieList_ = cookieList;
    this.filteredCookieList_ = cookieList;
  }

  /** @override */
  getDisplayList(filter, begin, count) {
    if (filter === undefined)
      filter = '';
    if (count == -1)
      count = this.cookieList_.length;
    let output = [];
    let end = Math.min(begin + count, this.cookieList_.length);
    for (let i = begin; i < end; ++i) {
      if (this.cookieList_[i].site.indexOf(filter) >= 0) {
        output.push(this.filteredCookieList_[i]);
      }
    }
    return Promise.resolve({items: output});
  }

  /** @override */
  removeAll() {
    this.methodCalled('removeAll');
    return Promise.resolve({id: null, children: []});
  }

  /** @override */
  removeShownItems() {
    this.methodCalled('removeShownItems');
  }

  /** @override */
  removeItem(id) {
    this.methodCalled('removeItem', id);
  }

  /** @override */
  getCookieDetails(site) {
    this.methodCalled('getCookieDetails', site);
    return Promise.resolve(this.cookieDetails_ || {id: '', children: []});
  }

  /** @override */
  reloadCookies() {
    this.methodCalled('reloadCookies');
    return Promise.resolve({id: null, children: []});
  }

  /** @override */
  removeCookie(path) {
    this.methodCalled('removeCookie', path);
  }
}
