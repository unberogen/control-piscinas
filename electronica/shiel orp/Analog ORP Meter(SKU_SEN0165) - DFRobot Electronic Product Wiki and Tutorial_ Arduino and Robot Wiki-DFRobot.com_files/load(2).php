var mediaWikiLoadStart=(new Date()).getTime(),mwPerformance=(window.performance&&performance.mark)?performance:{mark:function(){}};mwPerformance.mark('mwLoadStart');function isCompatible(str){var ua=str||navigator.userAgent;return!!('querySelector'in document&&'localStorage'in window&&'addEventListener'in window&&!(ua.match(/webOS\/1\.[0-4]/)||ua.match(/PlayStation/i)||ua.match(/SymbianOS|Series60|NetFront|Opera Mini|S40OviBrowser|MeeGo/)||(ua.match(/Glass/)&&ua.match(/Android/))));}(function(){var NORLQ,script;if(!isCompatible()){document.documentElement.className=document.documentElement.className.replace(/(^|\s)client-js(\s|$)/,'$1client-nojs$2');NORLQ=window.NORLQ||[];while(NORLQ.length){NORLQ.shift()();}window.NORLQ={push:function(fn){fn();}};window.RLQ={push:function(){}};return;}function startUp(){mw.config=new mw.Map(true);mw.loader.addSource({"local":"/wiki/load.php"});mw.loader.register([["site","kq+gWnhd"],["noscript","Xy2m+U18",[],"noscript"],["filepage","Th41pqRT"],[
"user.groups","8y1kbx+e",[],"user"],["user","9ibd+BaH",[],"user"],["user.cssprefs","GqV9IPpY",[],"private"],["user.defaults","us94jnHJ"],["user.options","C9rS/VRT",[6],"private"],["user.tokens","jeRDszHD",[],"private"],["mediawiki.language.data","bHbxm6Jh",[174]],["mediawiki.skinning.elements","3JTcT2l3"],["mediawiki.skinning.content","MRkgP9fT"],["mediawiki.skinning.interface","Gt6GnQCS"],["mediawiki.skinning.content.parsoid","qoaUV5eW"],["mediawiki.skinning.content.externallinks","08dJNMD4"],["jquery.accessKeyLabel","PHj8opTt",[25,130]],["jquery.appear","vkpm7cpm"],["jquery.arrowSteps","O9FPIZt6"],["jquery.async","+Obpb8Fd"],["jquery.autoEllipsis","0FkYEmPx",[37]],["jquery.badge","YQrUuO3P",[171]],["jquery.byteLength","mW6uuaiV"],["jquery.byteLimit","ZZrlGo6q",[21]],["jquery.checkboxShiftClick","QEt49S2V"],["jquery.chosen","ZYRcV36u"],["jquery.client","FDNUR41O"],["jquery.color","w4R/WU+C",[27]],["jquery.colorUtil","ds9NoXXP"],["jquery.confirmable","PRSUYH0p",[175]],["jquery.cookie",
"CCc/jSBF"],["jquery.expandableField","G0Krzhf7"],["jquery.farbtastic","SXcLbZeL",[27]],["jquery.footHovzer","PRVCSmG9"],["jquery.form","nFOov0ap"],["jquery.fullscreen","/Z8MUPoR"],["jquery.getAttrs","MP7HGCJS"],["jquery.hidpi","51ySbNq8"],["jquery.highlightText","5CaUbB6n",[242,130]],["jquery.hoverIntent","Y44TThFG"],["jquery.i18n","jK59fSbK",[173]],["jquery.localize","gC4VKwzD"],["jquery.makeCollapsible","gA/hR3Jq"],["jquery.mockjax","itU6QYux"],["jquery.mw-jump","aL3qylrq"],["jquery.mwExtension","LjOn+U96"],["jquery.placeholder","qThrKfrb"],["jquery.qunit","DPmlHjhI"],["jquery.qunit.completenessTest","4sTyqTFZ",[46]],["jquery.spinner","Dsf803dV"],["jquery.jStorage","LwVPE1se",[92]],["jquery.suggestions","80E5cARy",[37]],["jquery.tabIndex","MBF1Qv5Q"],["jquery.tablesorter","KR2CJ3M3",[242,130,176]],["jquery.textSelection","8BmYaliV",[25]],["jquery.throttle-debounce","vuLxamUI"],["jquery.xmldom","i7a4hxDI"],["jquery.tipsy","TkLz63zM"],["jquery.ui.core","DFOaDiSH",[58],"jquery.ui"],[
"jquery.ui.core.styles","o4QexbsQ",[],"jquery.ui"],["jquery.ui.accordion","yt1VGxu5",[57,77],"jquery.ui"],["jquery.ui.autocomplete","wwfpuMzy",[66],"jquery.ui"],["jquery.ui.button","QzSTYzJe",[57,77],"jquery.ui"],["jquery.ui.datepicker","4svqxjAl",[57],"jquery.ui"],["jquery.ui.dialog","3ZpLJB5V",[61,64,68,70],"jquery.ui"],["jquery.ui.draggable","tPPMr3dk",[57,67],"jquery.ui"],["jquery.ui.droppable","YH8WQXXB",[64],"jquery.ui"],["jquery.ui.menu","Cloyv7f1",[57,68,77],"jquery.ui"],["jquery.ui.mouse","VWDDftvg",[77],"jquery.ui"],["jquery.ui.position","1M08QNkg",[],"jquery.ui"],["jquery.ui.progressbar","RW8IlOCz",[57,77],"jquery.ui"],["jquery.ui.resizable","kkTR3E3z",[57,67],"jquery.ui"],["jquery.ui.selectable","/2DftgGY",[57,67],"jquery.ui"],["jquery.ui.slider","NtZ+Nxml",[57,67],"jquery.ui"],["jquery.ui.sortable","vz0qEc/W",[57,67],"jquery.ui"],["jquery.ui.spinner","0EkmmXIv",[61],"jquery.ui"],["jquery.ui.tabs","/bcakSBw",[57,77],"jquery.ui"],["jquery.ui.tooltip","mZC8PCia",[57,68,77],
"jquery.ui"],["jquery.ui.widget","S1TmKUjl",[],"jquery.ui"],["jquery.effects.core","Dq464UQ/",[],"jquery.ui"],["jquery.effects.blind","13cn69N1",[78],"jquery.ui"],["jquery.effects.bounce","LOSXJUkk",[78],"jquery.ui"],["jquery.effects.clip","WtLZnp83",[78],"jquery.ui"],["jquery.effects.drop","1zIxX2pm",[78],"jquery.ui"],["jquery.effects.explode","cgiJQqlz",[78],"jquery.ui"],["jquery.effects.fade","R4SW9YwH",[78],"jquery.ui"],["jquery.effects.fold","yv+hxl9i",[78],"jquery.ui"],["jquery.effects.highlight","QMk9cj92",[78],"jquery.ui"],["jquery.effects.pulsate","wuK15gO6",[78],"jquery.ui"],["jquery.effects.scale","ZI9BFKv4",[78],"jquery.ui"],["jquery.effects.shake","QiM2wScO",[78],"jquery.ui"],["jquery.effects.slide","IgNlukvS",[78],"jquery.ui"],["jquery.effects.transfer","XV93tQvw",[78],"jquery.ui"],["json","LQv9Mm04",[],null,null,"return!!(window.JSON\u0026\u0026JSON.stringify\u0026\u0026JSON.parse);"],["moment","dpkrLnzl"],["mediawiki.apihelp","rTke4lhk"],["mediawiki.template","MNc9eOeu"
],["mediawiki.template.mustache","hW1X+p3o",[95]],["mediawiki.template.regexp","rihxfume",[95]],["mediawiki.apipretty","ZrBEI+Ft"],["mediawiki.api","t9qlfg0L",[147,8]],["mediawiki.api.category","BXBi2GdS",[135,99]],["mediawiki.api.edit","LuHQaQDG",[135,99]],["mediawiki.api.login","dvYqe8ZD",[99]],["mediawiki.api.options","5a5R62BO",[99]],["mediawiki.api.parse","uYIzBSSi",[99]],["mediawiki.api.upload","mBqk47Aa",[242,92,101]],["mediawiki.api.user","+gYnuVWD",[99]],["mediawiki.api.watch","2aia7jja",[99]],["mediawiki.api.messages","Ae0MvOKa",[99]],["mediawiki.content.json","nWSCtfUU"],["mediawiki.confirmCloseWindow","vOBTJbXt"],["mediawiki.debug","y6QKeeKw",[32,56]],["mediawiki.debug.init","eAxEHHeE",[111]],["mediawiki.feedback","7LeaCUpu",[135,126,250]],["mediawiki.feedlink","FjSd9nID"],["mediawiki.filewarning","a5eaqSeN",[245]],["mediawiki.ForeignApi","0zy+J+Nh",[117]],["mediawiki.ForeignApi.core","IXe0jbIA",[99,243]],["mediawiki.helplink","c4rMNKUj"],["mediawiki.hidpi","u9i57Qxa",[36],
null,null,"return'srcset'in new Image();"],["mediawiki.hlist","wwA/4ikv"],["mediawiki.htmlform","Xi2Z1/Hl",[22,130]],["mediawiki.htmlform.styles","bSHzyi2J"],["mediawiki.htmlform.ooui.styles","sMDTKtl5"],["mediawiki.icon","r1dujkNI"],["mediawiki.inspect","wqJRMNU5",[21,92,130]],["mediawiki.messagePoster","hNtyBHvE",[116]],["mediawiki.messagePoster.wikitext","NTa2VXVv",[101,126]],["mediawiki.notification","NSSgcfEk",[183]],["mediawiki.notify","3f87GAyG"],["mediawiki.RegExp","vIa8h0ZM"],["mediawiki.pager.tablePager","mo5keLMi"],["mediawiki.searchSuggest","1cBmTMqi",[35,45,50,99]],["mediawiki.sectionAnchor","AdWik8qQ"],["mediawiki.storage","bFc6prRY"],["mediawiki.Title","1nnw3Ee/",[21,147]],["mediawiki.Upload","lD8yb7hY",[105]],["mediawiki.ForeignUpload","elG/p6GG",[116,136]],["mediawiki.ForeignStructuredUpload.config","JtmRymYi"],["mediawiki.ForeignStructuredUpload","2ph2X3mb",[138,137]],["mediawiki.Upload.Dialog","GldjIzis",[141]],["mediawiki.Upload.BookletLayout","uM2sM+Id",[136,175,
145,240,93,250,256,257]],["mediawiki.ForeignStructuredUpload.BookletLayout","sEX0vOjv",[139,141,108,179,236,234]],["mediawiki.toc","kAWNqWkY",[151]],["mediawiki.Uri","APl9tpNx",[147,97]],["mediawiki.user","z7AMFd9u",[106,151,7]],["mediawiki.userSuggest","pxUeFcAm",[50,99]],["mediawiki.util","JcyXmFdu",[15,129]],["mediawiki.viewport","3K2dDjdf"],["mediawiki.checkboxtoggle","mWbgQPdt"],["mediawiki.checkboxtoggle.styles","4/WOqjiS"],["mediawiki.cookie","6Rj9P2F0",[29]],["mediawiki.toolbar","suxV3ggQ"],["mediawiki.experiments","2fEVYmQi"],["mediawiki.raggett","FTSUcdWr"],["mediawiki.action.edit","S9GnaQy4",[22,53,156]],["mediawiki.action.edit.styles","nyzq1CSr"],["mediawiki.action.edit.collapsibleFooter","QTrkSZlh",[41,151,124]],["mediawiki.action.edit.preview","qZkzM66A",[33,48,53,161,99,175]],["mediawiki.action.edit.stash","1T8gOsrn",[35,99]],["mediawiki.action.history","v6Dvr9/F"],["mediawiki.action.history.diff","NE4nettF"],["mediawiki.action.view.dblClickEdit","6N9NaY4G",[183,7]],[
"mediawiki.action.view.metadata","CAmrt94N"],["mediawiki.action.view.categoryPage.styles","jUPALOy9"],["mediawiki.action.view.postEdit","hOUbqErZ",[151,175,95]],["mediawiki.action.view.redirect","g5/WiiS8",[25]],["mediawiki.action.view.redirectPage","hareY0K4"],["mediawiki.action.view.rightClickEdit","Fk+CPIK7"],["mediawiki.action.edit.editWarning","o8BqgiRN",[53,110,175]],["mediawiki.action.view.filepage","9f5pZaFD"],["mediawiki.language","DwS30xVu",[172,9]],["mediawiki.cldr","Ee05l6gX",[173]],["mediawiki.libs.pluralruleparser","zcFJsL7F"],["mediawiki.language.init","SLJ9Qb0b"],["mediawiki.jqueryMsg","3BFJOerX",[242,171,147,7]],["mediawiki.language.months","Q6jFkbX9",[171]],["mediawiki.language.names","dVn8oVHH",[174]],["mediawiki.language.specialCharacters","v31HqVfX",[171]],["mediawiki.libs.jpegmeta","oIwPh2GW"],["mediawiki.page.gallery","QQx3MIVj",[54,181]],["mediawiki.page.gallery.styles","JfyiYid2"],["mediawiki.page.ready","TzItbmzH",[15,23,41,43,45]],["mediawiki.page.startup",
"j/8mAyCk",[147]],["mediawiki.page.patrol.ajax","yjk84NpA",[48,135,99,183]],["mediawiki.page.watch.ajax","SSRqVWcr",[107,183]],["mediawiki.page.image.pagination","nEYk68UD",[48,147]],["mediawiki.special","VptAp5zT"],["mediawiki.special.apisandbox.styles","MZKdOKxK"],["mediawiki.special.apisandbox","rbIgZ84W",[99,175,187,235,244]],["mediawiki.special.block","THBZSWfD",[147]],["mediawiki.special.blocklist","tIeJEMO/"],["mediawiki.special.changeslist","Uy51Tigi"],["mediawiki.special.changeslist.legend","T9dgi308"],["mediawiki.special.changeslist.legend.js","ZHfRopTw",[41,151]],["mediawiki.special.changeslist.enhanced","HQ0+RYmE"],["mediawiki.special.changeslist.visitedstatus","ax9IvlAh"],["mediawiki.special.comparepages.styles","rF+DpgeU"],["mediawiki.special.edittags","AU/Qjx1u",[24]],["mediawiki.special.edittags.styles","T6j1mBqk"],["mediawiki.special.import","sk+fXHoR"],["mediawiki.special.movePage","5S96Gtmq",[232]],["mediawiki.special.movePage.styles","9i5x0QAh"],[
"mediawiki.special.pageLanguage","MWhXljp7",[245]],["mediawiki.special.pagesWithProp","KK2SH2gy"],["mediawiki.special.preferences","RBPq37S+",[110,171,128]],["mediawiki.special.preferences.styles","/Dp5EsDl"],["mediawiki.special.recentchanges","uQRkyBiG",[187]],["mediawiki.special.search","9cl2ZY20",[238]],["mediawiki.special.undelete","JMcIwMWe"],["mediawiki.special.upload","w8CU9Qbb",[48,135,99,110,175,179,95]],["mediawiki.special.userlogin.common.styles","GrboXLDB"],["mediawiki.special.userlogin.signup.styles","l9bVNCmh"],["mediawiki.special.userlogin.login.styles","AwXRwM+M"],["mediawiki.special.userlogin.signup.js","iiLE13yg",[54,99,175]],["mediawiki.special.unwatchedPages","jPZ+ofGD",[135,107]],["mediawiki.special.watchlist","s6efWPV2"],["mediawiki.special.version","eoBowBG7"],["mediawiki.legacy.config","e94JRlu+"],["mediawiki.legacy.commonPrint","nWefJLL0"],["mediawiki.legacy.protect","pLHP8n0k",[22]],["mediawiki.legacy.shared","10DmgeCV"],["mediawiki.legacy.oldshared",
"tvNgaiR3"],["mediawiki.legacy.wikibits","w+uoMDD3",[147]],["mediawiki.ui","ms8DcfEv"],["mediawiki.ui.checkbox","JIOcaYfN"],["mediawiki.ui.radio","/bkIJ44T"],["mediawiki.ui.anchor","6WcGfL7K"],["mediawiki.ui.button","n0NMXmow"],["mediawiki.ui.input","0yzmZB3B"],["mediawiki.ui.icon","HaUlPkef"],["mediawiki.ui.text","WIHnJV+A"],["mediawiki.widgets","j5Qj+pyP",[19,22,135,99,233,248]],["mediawiki.widgets.styles","ySJdBVT4"],["mediawiki.widgets.DateInputWidget","8QAZ4C2C",[93,248]],["mediawiki.widgets.datetime","b5PTMdDr",[245]],["mediawiki.widgets.CategorySelector","cJ9pT71q",[116,135,248]],["mediawiki.widgets.UserInputWidget","XAeXrLmW",[248]],["mediawiki.widgets.SearchInputWidget","YnOqJW03",[132,232]],["mediawiki.widgets.SearchInputWidget.styles","R2R0/BZQ"],["mediawiki.widgets.StashedFileWidget","39Bw3ZcF",[245]],["es5-shim","wIzKIQM4",[],null,null,"return(function(){'use strict';return!this\u0026\u0026!!Function.prototype.bind;}());"],["dom-level2-shim","hFTEQ+dl",[],null,null,
"return!!window.Node;"],["oojs","SD3Z6E0r",[241,92]],["oojs-ui","9ilCslmD",[249,248,250]],["oojs-ui-core","UWrMdRhn",[171,243,246]],["oojs-ui-core.styles","dTubQBuS",[251,252,253],null,null,"return!!jQuery('meta[name=\"X-OOUI-PHP\"]').length;"],["oojs-ui.styles","3plr6hRn",[251,252,253],null,null,"return!!jQuery('meta[name=\"X-OOUI-PHP\"]').length;"],["oojs-ui-widgets","yACSnYAS",[245]],["oojs-ui-toolbars","A3sOjU8p",[245]],["oojs-ui-windows","IZuavxDT",[245]],["oojs-ui.styles.icons","4wTplTmN"],["oojs-ui.styles.indicators","2aGyfmfc"],["oojs-ui.styles.textures","GUgJ7i6d"],["oojs-ui.styles.icons-accessibility","2Ko0q0ie"],["oojs-ui.styles.icons-alerts","k7/KwTev"],["oojs-ui.styles.icons-content","jnyqwdfR"],["oojs-ui.styles.icons-editing-advanced","XyxoxGty"],["oojs-ui.styles.icons-editing-core","uAKgR4Z/"],["oojs-ui.styles.icons-editing-list","iPSFk2Ww"],["oojs-ui.styles.icons-editing-styling","xWryh7ba"],["oojs-ui.styles.icons-interactions","Gx2vljRa"],["oojs-ui.styles.icons-layout"
,"3bwNpFqr"],["oojs-ui.styles.icons-location","ll5eUUCI"],["oojs-ui.styles.icons-media","DQ0nSWIc"],["oojs-ui.styles.icons-moderation","2o7qBc/P"],["oojs-ui.styles.icons-movement","0XcZUxJu"],["oojs-ui.styles.icons-user","a1W86WiP"],["oojs-ui.styles.icons-wikimedia","d62AaFMc"],["skins.vector.styles","HN+91qr8"],["skins.vector.styles.responsive","e9etd+Cl"],["skins.vector.js","Im6X6YVR",[51,54]],["Base64.js","gN+bQ68P"],["easy-deflate.core","tzapiFVY",[272]],["easy-deflate.deflate","/G/QWfW8",[273]],["unicodejs","uOn+AXUC"],["unicodejs.wordbreak","9ilCslmD",[275]],["papaparse","rexnlp6c"],["dom-classlist-shim","6p9lxz6y",[],null,null,"return!!('classList'in document.createElement('_')\u0026\u0026!(document.createElementNS\u0026\u0026!('classList'in document.createElementNS('http://www.w3.org/2000/svg','g'))));"],["rangefix","2KYmcv91"],["ext.visualEditor.supportCheck","yM4PCjsw"],["ext.visualEditor.desktopArticleTarget.init","kYyo1aQU",[280,287,135,144,165,103,183,145]],[
"ext.visualEditor.desktopArticleTarget.noscript","dcNRzD5+"],["ext.visualEditor.targetLoader","+K7NTXrI",[287,99]],["ext.visualEditor.desktopTarget","HHQQ9fJO"],["ext.visualEditor.desktopArticleTarget","xj9B9eZQ",[293,284,289,175]],["ext.visualEditor.ve","3vE2IlqO"],["ext.visualEditor.track","fVnPdVwP",[286]],["ext.visualEditor.base","1W332CuF",[286,244,275]],["ext.visualEditor.mediawiki","J0xUS+si",[288,283,319,135,144,103,145]],["ext.visualEditor.standalone","DpUiStTs",[288,39,319]],["ext.visualEditor.data","I6DsAHVk",[289]],["ext.visualEditor.core","5mw7mhGf",[278,288,280,25,277,279]],["ext.visualEditor.core.desktop","ScVPX1zi",[292]],["ext.visualEditor.switching","LSmraFVK",[244,258]],["ext.visualEditor.mwcore","Km821MBM",[292,294,161,175,13,145,232]],["ext.visualEditor.mwformatting","UqPFDviW",[295]],["ext.visualEditor.mwimage.core","XLt/vhsO",[295]],["ext.visualEditor.mwimage","539MaRkn",[297,142,261,264,268]],["ext.visualEditor.mwlink","Ce5pSQ09",[295]],[
"ext.visualEditor.mwmeta","9TDDXwbB",[299,167]],["ext.visualEditor.mwtransclusion.core","0aZ85C0Q",[295]],["ext.visualEditor.mwtransclusion","NiSc3BPU",[301,237]],["ext.visualEditor.language","BHWFpO6s",[292,319,177]],["ext.visualEditor.mwalienextension","CKALbTmu",[295]],["ext.visualEditor.mwgallery","7eve76SB",[295,181,264]],["ext.visualEditor.mwsignature","MoPG1uiQ",[302,255]],["ext.visualEditor.experimental","9ilCslmD",[303]],["ext.visualEditor.icons","Sa8SKnJh",[257,258,259,260,252,253]],["ext.pygments","bniPKE9s"],["ext.geshi.visualEditor","y8YVhAy4",[295]],["ext.templateData","DxrngMT5"],["ext.templateDataGenerator.editPage","WXjN1NSf",[314]],["ext.templateDataGenerator.data","RyflYtvj",[243]],["ext.templateDataGenerator.ui","wL4jCfML",[311,313,319,244]],["ext.bootstrap.styles","CvXt2vcd"],["ext.bootstrap.scripts","uBR0cVk2"],["ext.bootstrap","9ilCslmD",[316,315]],["skin.chameleon.jquery-sticky","8im0ATWq",[],"skin.chameleon"],["jquery.uls.data","7czoeBr1"]]);;mw.config.set({
"wgLoadScript":"/wiki/load.php","debug":!1,"skin":"chameleon","stylepath":"/wiki/skins","wgUrlProtocols":"bitcoin\\:|ftp\\:\\/\\/|ftps\\:\\/\\/|geo\\:|git\\:\\/\\/|gopher\\:\\/\\/|http\\:\\/\\/|https\\:\\/\\/|irc\\:\\/\\/|ircs\\:\\/\\/|magnet\\:|mailto\\:|mms\\:\\/\\/|news\\:|nntp\\:\\/\\/|redis\\:\\/\\/|sftp\\:\\/\\/|sip\\:|sips\\:|sms\\:|ssh\\:\\/\\/|svn\\:\\/\\/|tel\\:|telnet\\:\\/\\/|urn\\:|worldwind\\:\\/\\/|xmpp\\:|\\/\\/","wgArticlePath":"/wiki/index.php/$1","wgScriptPath":"/wiki","wgScriptExtension":".php","wgScript":"/wiki/index.php","wgSearchType":null,"wgVariantArticlePath":!1,"wgActionPaths":{},"wgServer":"https://www.dfrobot.com","wgServerName":"www.dfrobot.com","wgUserLanguage":"en","wgContentLanguage":"en","wgTranslateNumerals":!0,"wgVersion":"1.27.1","wgEnableAPI":!0,"wgEnableWriteAPI":!0,"wgMainPageTitle":"Main Page","wgFormattedNamespaces":{"-2":"Media","-1":"Special","0":"","1":"Talk","2":"User","3":"User talk","4":"Robot Wiki","5":"Robot Wiki talk","6":
"File","7":"File talk","8":"MediaWiki","9":"MediaWiki talk","10":"Template","11":"Template talk","12":"Help","13":"Help talk","14":"Category","15":"Category talk"},"wgNamespaceIds":{"media":-2,"special":-1,"":0,"talk":1,"user":2,"user_talk":3,"robot_wiki":4,"robot_wiki_talk":5,"file":6,"file_talk":7,"mediawiki":8,"mediawiki_talk":9,"template":10,"template_talk":11,"help":12,"help_talk":13,"category":14,"category_talk":15,"image":6,"image_talk":7,"project":4,"project_talk":5},"wgContentNamespaces":[0],"wgSiteName":"DFRobot Electronic Product Wiki and Tutorial: Arduino and Robot Wiki-DFRobot.com","wgDBname":"df_wikiv3","wgExtraSignatureNamespaces":[],"wgAvailableSkins":{"vector":"Vector","chameleon":"Chameleon","fallback":"Fallback","apioutput":"ApiOutput"},"wgExtensionAssetsPath":"/wiki/extensions","wgCookiePrefix":"df_wikiv3_wk","wgCookieDomain":"","wgCookiePath":"/","wgCookieExpiration":15552000,"wgResourceLoaderMaxQueryLength":2000,"wgCaseSensitiveNamespaces":[],"wgLegalTitleChars":
" %!\"$&'()*,\\-./0-9:;=?@A-Z\\\\\\^_`a-z~+\\u0080-\\uFFFF","wgResourceLoaderStorageVersion":1,"wgResourceLoaderStorageEnabled":!1,"wgResourceLoaderLegacyModules":[],"wgForeignUploadTargets":[],"wgEnableUploads":!0,"wgVisualEditorConfig":{"disableForAnons":!1,"preferenceModules":{"visualeditor-enable-experimental":"ext.visualEditor.experimental"},"namespaces":[2,0],"signatureNamespaces":[],"pluginModules":["ext.geshi.visualEditor"],"defaultUserOptions":{"defaultthumbsize":300},"blacklist":{"msie":[["<=",8]],"android":[["<",3]],"firefox":[["<=",14]],"safari":[["<=",6]],"opera":[["<",12]],"blackberry":null,"silk":null},"skins":["vector","apex","monobook","minerva","blueprint","chameleon"],"tabPosition":"before","tabMessages":{"edit":null,"editsource":"visualeditor-ca-editsource","create":null,"createsource":"visualeditor-ca-createsource","editlocaldescriptionsource":"visualeditor-ca-editlocaldescriptionsource","createlocaldescriptionsource":
"visualeditor-ca-createlocaldescriptionsource","editsection":null,"editsectionsource":"visualeditor-ca-editsource-section"},"singleEditTab":!1,"showBetaWelcome":!0,"enableTocWidget":!1,"svgMaxSize":5120,"namespacesWithSubpages":{"1":!0,"2":!0,"3":!0,"4":!0,"5":!0,"7":!0,"8":!0,"9":!0,"11":!0,"12":!0,"13":!0,"15":!0},"specialBooksources":"Special:BookSources","restbaseUrl":!1,"fullRestbaseUrl":!1,"feedbackApiUrl":!1,"feedbackTitle":!1}});var RLQ=window.RLQ||[];while(RLQ.length){RLQ.shift()();}window.RLQ={push:function(fn){fn();}};window.NORLQ={push:function(){}};}script=document.createElement('script');script.src="/wiki/load.php?debug=false&lang=en&modules=jquery%2Cmediawiki&only=scripts&skin=chameleon&version=%2B0rbRdh8";script.onload=script.onreadystatechange=function(){if(!script.readyState||/loaded|complete/.test(script.readyState)){script.onload=script.onreadystatechange=null;script=null;startUp();}};document.getElementsByTagName('head')[
0].appendChild(script);}());