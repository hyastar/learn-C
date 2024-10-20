<%* 
let tencentIpUrl = 'https://apis.map.qq.com/ws/location/v1/ip';
let tencentKey = 'PJCBZ-XXYEZ-EF3XX-TD63T-GAQY6-SDBW7';
let weatherUrl = 'https://restapi.amap.com/v3/weather/weatherInfo';
let key = '03d9337afc0a9c2016fd0d486b7570c4'; 

let ipResult = eval("(" + await request({url: tencentIpUrl + `?key=${tencentKey}`, method: "GET"}) + ")").result
console.log("ipResult: ", ipResult)

let adcode = ipResult.ad_info.adcode
console.log("adcode: " + adcode)

let 位置 = ''
let 天气 = ''
let 温度 = ''
let 风向 = ''
await fetch(weatherUrl + `?key=${key}&city=${adcode}&extensions=all`)
.then(res => res.json())
.then((data) => {
	let info = data.forecasts[0]
	
	console.log("info:" + info)
	
	位置 = info.province + '-' + info.city
	天气 = '🌅' + info.casts[0].dayweather + ' / 🌃' + info.casts[0].nightweather
	温度 = '🌅' + info.casts[0].daytemp_float + '℃' + '/ 🌃' + info.casts[0].nighttemp_float + '℃'
})
-%>

---
🌻日期🌻: <% tp.file.creation_date("YYYY MM DD HH:mm:ss") %>
🌙星期🌙: <% tp.file.creation_date("dddd") %>
⌚️时间⌚️: <% tp.file.creation_date("HH:mm:ss") %>
🌍位置🌍: <% 位置 %>
☁️天气☁️: <% 天气 %>
🌡️温度🌡️: <% 温度 %>

---
<%*
let 一言 = ""
let 来源 = ""
let 作者 = ""

await fetch('https://v1.hitokoto.cn/?c=d&c=h&c=i&c=j')
.then(response => response.json())
.then(data => { 
	一言 = data.hitokoto
	来源 = data.from
	作者 = data.from_who === null ? '佚名' : data.from_who
})
-%>
>[!quote] 一言
 <% 一言 %>  —— 《<% 来源 %>》 · <% 作者 %>

---

<%*

let quote = "";

let author = "";

  

try {

    const quoteResponse = await tp.obsidian.request({

        url: 'https://api.quotable.io/random',

        method: "GET"

    });

    const data = JSON.parse(quoteResponse);

    quote = data.content;

    author = data.author;

} catch (error) {

    console.error("Error fetching quote:", error);

}

-%>

>[!quote] Quote

 <% quote %>  —— <% author %>

---

# Tracking


# Diary




---
<< [[<% tp.date.now("YYYY-MM-DD", -1) %>]] | [[<% tp.date.now("YYYY-MM-DD", 1) %>]] >>