[@bs.scope ("window", "location")] [@bs.val]
external reload : (~forceReload: bool=?, unit) => unit = "";

let reload = reload;