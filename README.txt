Multi File URL Tamper
=====================

This drupal module adds a new tamper plugin which allows to import multiple files into same field: Given a string containing concatenated URL with no separator, it process the string and separates all URL.

Input example:
http://www.google.comhttps://es.yahoo.com/http://www.bing.com/

Input for feeds module using this tamper plugin:
Array ( [0] => http://www.google.com [1] => https://es.yahoo.com/ [2] => http://www.bing.com/ )

Important note: To import files by it's URI you need to use Feeds > 7.x-2.0-alpha8. While a newer stable version it's no available use the dev branch of the module.
