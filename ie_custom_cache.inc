<?php

/**
 * @file
 * Cache backend include for the ie_custom_cache module.
 */

/**
 * To use this functionality, the following needs to be added to settings.php
 * $conf['cache_backends'][] = 'sites/all/modules/ie_custom_cache/ie_custom_cache.inc';
 * $conf['cache_class_cache_page'] = 'IeCustomCache';
 */
class IeCustomCache extends DrupalDatabaseCache implements DrupalCacheInterface {

  /**
   * {@inheritdoc}
   */
  function __construct($bin) {
    parent::__construct($bin);
  }

  /**
   * {@inheritdoc}
   */
  function set($cid, $data, $expire = CACHE_PERMANENT) {
    $cid = $this -> ie_custom_cache_alter_cid() . $cid;
    parent::set($cid, $data, $expire);
  }

  /**
   * {@inheritdoc}
   */
  function getMultiple(&$cids) {
    if (is_array($cids)) {
      foreach ($cids as $key => $cid) {
        $cids[$key] = $this -> ie_custom_cache_alter_cid() . $cid;
      }
    }
    return parent::getMultiple($cids);
  }

  /**
   * Determines a prefix for the page cache $cid based on devide type.
   *
   * @return string
   *   The $cid prefix
   */
  protected function ie_custom_cache_alter_cid() {
    $device = '';

    try {

      //if akamai headers theme says mobile do stuff
      $device = 'ie_mobile:';

    } catch (Exception $e) {
      //Do nothing ??
    }

    return $device;
  }

}
