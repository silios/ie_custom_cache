# ie_custom_cache
Custom caching object module that overides Drupal 7 default behavior

8/9/2015 - marios.tsalkidis@gmail.com 

Problem : 
Drupal 7 core cache mechanism cannot distinguish mobile from desktop versions of the same page when using external caching services such as AKAMAI, CLOUDFLARE etc.

Solution : 
Extend DrupalDatabaseCache class to provide fine grained CID's for objects.
In this module, if a header from an external caching service is set, we create a separate object for mobile and desktop versions.
 
To use this functionality, the following needs to be added to settings.php
$conf['cache_backends'][] = 'sites/all/modules/ie_custom_cache/ie_custom_cache.inc';
$conf['cache_class_cache_page'] = 'IeCustomCache';
