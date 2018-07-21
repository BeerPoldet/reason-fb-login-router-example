type localStorage;

[@bs.val] [@bs.scope ("window", "localStorage")] [@bs.return nullable]
external getItem : (~key: string) => option(string) = "";

[@bs.val] [@bs.scope ("window", "localStorage")]
external setItem : (~key: string, ~value: string) => unit = "";

[@bs.val] [@bs.scope ("window", "localStorage")]
external removeItem : (~key: string) => unit = "";

let getItem = getItem;
let setItem = setItem;
let removeItem = removeItem;