




<!DOCTYPE html>
<html class="   ">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    
    
    <title>DOSMAN/doc/SPEC.md at master · Marneus68/DOSMAN</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <meta property="fb:app_id" content="1401488693436528"/>

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="Marneus68/DOSMAN" name="twitter:title" /><meta content="DOSMAN is a graphical DosBox front-end written in C++ for modern GNU/Linux dekstops environements." name="twitter:description" /><meta content="https://avatars2.githubusercontent.com/u/878305?s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars2.githubusercontent.com/u/878305?s=400" property="og:image" /><meta content="Marneus68/DOSMAN" property="og:title" /><meta content="https://github.com/Marneus68/DOSMAN" property="og:url" /><meta content="DOSMAN is a graphical DosBox front-end written in C++ for modern GNU/Linux dekstops environements." property="og:description" />

    <link rel="assets" href="https://assets-cdn.github.com/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035/">
    <link rel="xhr-socket" href="/_sockets" />

    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="6D08ECE1:522A:62504:5373C890" name="octolytics-dimension-request_id" /><meta content="878305" name="octolytics-actor-id" /><meta content="Marneus68" name="octolytics-actor-login" /><meta content="9bb8ff509cc820e175febb82a0932d00ce862a2290050e363c664b2f0ab3d0d9" name="octolytics-actor-hash" />
    

    
    
    <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="qFhwMfcy3qeUjCFhaeOC0rb/Dy2TsZzSOSROCHqg8p4ZchPvWTMtGkbS4PTt9wo1PGCOhkbEiyqqQtnfyB4E7A==" name="csrf-token" />

    <link href="https://assets-cdn.github.com/assets/github-08eca722f10c5a963656d215e35a809b85c86d1e.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://assets-cdn.github.com/assets/github2-50bd4d5d683bdda80f061b5d079826bd642a2787.css" media="all" rel="stylesheet" type="text/css" />
    


    <meta http-equiv="x-pjax-version" content="8f882ae42120fd172a3d81adab0f2690">

      
  <meta name="description" content="DOSMAN is a graphical DosBox front-end written in C++ for modern GNU/Linux dekstops environements." />

  <meta content="878305" name="octolytics-dimension-user_id" /><meta content="Marneus68" name="octolytics-dimension-user_login" /><meta content="15367555" name="octolytics-dimension-repository_id" /><meta content="Marneus68/DOSMAN" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="15367555" name="octolytics-dimension-repository_network_root_id" /><meta content="Marneus68/DOSMAN" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/Marneus68/DOSMAN/commits/master.atom" rel="alternate" title="Recent Commits to DOSMAN:master" type="application/atom+xml" />

  </head>


  <body class="logged_in  env-production linux vis-public page-blob">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/">
  <span class="mega-octicon octicon-mark-github"></span>
</a>

    
    <a href="/notifications" aria-label="You have unread notifications" class="notification-indicator tooltipped tooltipped-s" data-hotkey="g n">
        <span class="mail-status unread"></span>
</a>

      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<div class="commandbar">
  <span class="message"></span>
  <input type="text" data-hotkey="s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    data-username="Marneus68"
      data-repo="Marneus68/DOSMAN"
      data-branch="master"
      data-sha="1489f5e5cf82051404ffc6d3f0edb2674cfcf2e7"
  >
  <div class="display hidden"></div>
</div>

    <input type="hidden" name="nwo" value="Marneus68/DOSMAN" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target" role="button" aria-haspopup="true">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container" aria-hidden="true">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="help tooltipped tooltipped-s" aria-label="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
        <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="https://help.github.com">Help</a></li>
        </ul>
      </div>

    


  <ul id="user-links">
    <li>
      <a href="/Marneus68" class="name">
        <img alt="Duane Bekaert" class=" js-avatar" data-user="878305" height="20" src="https://avatars1.githubusercontent.com/u/878305?s=140" width="20" /> Marneus68
      </a>
    </li>

    <li class="new-menu dropdown-toggle js-menu-container">
      <a href="#" class="js-menu-target tooltipped tooltipped-s" aria-label="Create new...">
        <span class="octicon octicon-plus"></span>
        <span class="dropdown-arrow"></span>
      </a>

      <div class="new-menu-content js-menu-content">
      </div>
    </li>

    <li>
      <a href="/settings/profile" id="account_settings"
        class="tooltipped tooltipped-s"
        aria-label="Account settings ">
        <span class="octicon octicon-tools"></span>
      </a>
    </li>
    <li>
      <form class="logout-form" action="/logout" method="post">
        <button class="sign-out-button tooltipped tooltipped-s" aria-label="Sign out">
          <span class="octicon octicon-log-out"></span>
        </button>
      </form>
    </li>

  </ul>

<div class="js-new-dropdown-contents hidden">
  

<ul class="dropdown-menu">
  <li>
    <a href="/new"><span class="octicon octicon-repo-create"></span> New repository</a>
  </li>
  <li>
    <a href="/organizations/new"><span class="octicon octicon-organization"></span> New organization</a>
  </li>


    <li class="section-title">
      <span title="Marneus68/DOSMAN">This repository</span>
    </li>
      <li>
        <a href="/Marneus68/DOSMAN/issues/new"><span class="octicon octicon-issue-opened"></span> New issue</a>
      </li>
      <li>
        <a href="/Marneus68/DOSMAN/settings/collaboration"><span class="octicon octicon-person-add"></span> New collaborator</a>
      </li>
</ul>

</div>


    
  </div>
</div>

      

        



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    <div id="js-flash-container">
      
    </div>
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        

<ul class="pagehead-actions">

    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="riWyi63+seb2UuDw8UI9F0Mof3Jfwq8TaJ6XI/A3eDERY3O2l7Cw8EwGzoJyU29EqYKfOke7AXjLNS6xm9cRPw==" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="15367555" />

    <div class="select-menu js-menu-container js-select-menu">
      <a class="social-count js-social-count" href="/Marneus68/DOSMAN/watchers">
        2
      </a>
      <span class="minibutton select-menu-button with-count js-menu-target" role="button" tabindex="0" aria-haspopup="true">
        <span class="js-select-button">
          <span class="octicon octicon-eye-unwatch"></span>
          Unwatch
        </span>
      </span>

      <div class="select-menu-modal-holder">
        <div class="select-menu-modal subscription-menu-modal js-menu-content" aria-hidden="true">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="octicon octicon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container" role="menu">

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for conversations in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-watch"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

  <li>
  

  <div class="js-toggler-container js-social-container starring-container ">

    <form accept-charset="UTF-8" action="/Marneus68/DOSMAN/unstar" class="js-toggler-form starred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="NYcmtELhAnwYQ4u5ujfOSZu8UaHhGj+RvV5Nkcmy7xIXA6lc8RBS/qvUbr+WSUJoRUPls5kkxaF6gCFbY2CY1g==" /></div>
      <button
        class="minibutton with-count js-toggler-target star-button"
        aria-label="Unstar this repository" title="Unstar Marneus68/DOSMAN">
        <span class="octicon octicon-star-delete"></span><span class="text">Unstar</span>
      </button>
        <a class="social-count js-social-count" href="/Marneus68/DOSMAN/stargazers">
          0
        </a>
</form>
    <form accept-charset="UTF-8" action="/Marneus68/DOSMAN/star" class="js-toggler-form unstarred" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="3BOS7zjKnMKCxwCXbqMedqa1Ah4o/wgjM2m9uxKnUfhHwZxEFSbYs9sQSljuh9kVtxb8YOYEduA0NVyPgetyQg==" /></div>
      <button
        class="minibutton with-count js-toggler-target star-button"
        aria-label="Star this repository" title="Star Marneus68/DOSMAN">
        <span class="octicon octicon-star"></span><span class="text">Star</span>
      </button>
        <a class="social-count js-social-count" href="/Marneus68/DOSMAN/stargazers">
          0
        </a>
</form>  </div>

  </li>


        <li>
          <a href="/Marneus68/DOSMAN/fork" class="minibutton with-count js-toggler-target fork-button lighter tooltipped-n" title="Fork your own copy of Marneus68/DOSMAN to your account" aria-label="Fork your own copy of Marneus68/DOSMAN to your account" rel="facebox nofollow">
            <span class="octicon octicon-git-branch-create"></span><span class="text">Fork</span>
          </a>
          <a href="/Marneus68/DOSMAN/network" class="social-count">0</a>
        </li>


</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="repo-label"><span>public</span></span>
          <span class="mega-octicon octicon-repo"></span>
          <span class="author"><a href="/Marneus68" class="url fn" itemprop="url" rel="author"><span itemprop="title">Marneus68</span></a></span><!--
       --><span class="path-divider">/</span><!--
       --><strong><a href="/Marneus68/DOSMAN" class="js-current-repository js-repo-home-link">DOSMAN</a></strong>

          <span class="page-context-loader">
            <img alt="Octocat-spinner-32" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline js-new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped tooltipped-w" aria-label="Code">
        <a href="/Marneus68/DOSMAN" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-hotkey="g c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /Marneus68/DOSMAN">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

        <li class="tooltipped tooltipped-w" aria-label="Issues">
          <a href="/Marneus68/DOSMAN/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g i" data-selected-links="repo_issues /Marneus68/DOSMAN/issues">
            <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
            <span class='counter'>0</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>

      <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
        <a href="/Marneus68/DOSMAN/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g p" data-selected-links="repo_pulls /Marneus68/DOSMAN/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class='counter'>0</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


        <li class="tooltipped tooltipped-w" aria-label="Wiki">
          <a href="/Marneus68/DOSMAN/wiki" aria-label="Wiki" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g w" data-selected-links="repo_wiki /Marneus68/DOSMAN/wiki">
            <span class="octicon octicon-book"></span> <span class="full-word">Wiki</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>
    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped tooltipped-w" aria-label="Pulse">
        <a href="/Marneus68/DOSMAN/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /Marneus68/DOSMAN/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Graphs">
        <a href="/Marneus68/DOSMAN/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /Marneus68/DOSMAN/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Network">
        <a href="/Marneus68/DOSMAN/network" aria-label="Network" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-selected-links="repo_network /Marneus68/DOSMAN/network">
          <span class="octicon octicon-git-branch"></span> <span class="full-word">Network</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


      <div class="sunken-menu-separator"></div>
      <ul class="sunken-menu-group">
        <li class="tooltipped tooltipped-w" aria-label="Settings">
          <a href="/Marneus68/DOSMAN/settings" aria-label="Settings" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_settings /Marneus68/DOSMAN/settings">
            <span class="octicon octicon-tools"></span> <span class="full-word">Settings</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>
      </ul>
  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=push">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/Marneus68/DOSMAN.git" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/Marneus68/DOSMAN.git" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="ssh"
  data-url="/users/set_protocol?protocol_selector=ssh&amp;protocol_type=push">
  <h3><strong>SSH</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="git@github.com:Marneus68/DOSMAN.git" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="git@github.com:Marneus68/DOSMAN.git" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=push">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/Marneus68/DOSMAN" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/Marneus68/DOSMAN" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>,
      <a href="#" class="js-clone-selector" data-protocol="ssh">SSH</a>,
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <span class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <a href="https://help.github.com/articles/which-remote-url-should-i-use">
    <span class="octicon octicon-question"></span>
    </a>
  </span>
</p>



                <a href="/Marneus68/DOSMAN/archive/master.zip"
                   class="minibutton sidebar-button"
                   aria-label="Download Marneus68/DOSMAN as a zip file"
                   title="Download Marneus68/DOSMAN as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          


<a href="/Marneus68/DOSMAN/blob/83836e84437b63e3772a93301eba2557e3c8f26c/doc/SPEC.md" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:0711e6f8ca97c0f7cc76636b9c888809 -->

<p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

<a href="/Marneus68/DOSMAN/find/master" data-pjax data-hotkey="t" class="js-show-file-finder" style="display:none">Show File Finder</a>

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu" >
  <span class="minibutton select-menu-button js-menu-target" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-remove-close js-menu-close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Find or create a branch…" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Find or create a branch…">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Marneus68/DOSMAN/blob/master/doc/SPEC.md"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <form accept-charset="UTF-8" action="/Marneus68/DOSMAN/branches" class="js-create-branch select-menu-item select-menu-new-item-form js-navigation-item js-new-item-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="R+nu4y8i4geQWA0ijfeS9u5jDR8WVBOqNu+S+FMAhnJoBS32YRe9zomsipaN6e0/drhb5tnoFCjBu8btkpDbMQ==" /></div>
            <span class="octicon octicon-git-branch-create select-menu-item-icon"></span>
            <div class="select-menu-item-text">
              <h4>Create branch: <span class="js-new-item-name"></span></h4>
              <span class="description">from ‘master’</span>
            </div>
            <input type="hidden" name="name" id="name" class="js-new-item-value">
            <input type="hidden" name="branch" id="branch" value="master" />
            <input type="hidden" name="path" id="path" value="doc/SPEC.md" />
          </form> <!-- /.select-menu-item -->

      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Marneus68/DOSMAN" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">DOSMAN</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Marneus68/DOSMAN/tree/master/doc" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">doc</span></a></span><span class="separator"> / </span><strong class="final-path">SPEC.md</strong> <button aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="doc/SPEC.md" data-copied-hint="copied!" type="button"><span class="octicon octicon-clippy"></span></button>
  </div>
</div>


  <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/Marneus68/DOSMAN/contributors/master/doc/SPEC.md">
    Fetching contributors…

    <div class="participation">
      <p class="loader-loading"><img alt="Octocat-spinner-32-eaf2f5" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32-EAF2F5.gif" width="16" /></p>
      <p class="loader-error">Cannot retrieve contributors at this time</p>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
        <span class="icon"><b class="octicon octicon-file-text"></b></span>
        <span class="mode" title="File Mode">file</span>
        <span class="meta-divider"></span>
          <span>64 lines (40 sloc)</span>
          <span class="meta-divider"></span>
        <span>4.331 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
                <a class="minibutton js-update-url-with-hash"
                   href="/Marneus68/DOSMAN/edit/master/doc/SPEC.md"
                   data-method="post" rel="nofollow" data-hotkey="e">Edit</a>
          <a href="/Marneus68/DOSMAN/raw/master/doc/SPEC.md" class="button minibutton " id="raw-url">Raw</a>
            <a href="/Marneus68/DOSMAN/blame/master/doc/SPEC.md" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/Marneus68/DOSMAN/commits/master/doc/SPEC.md" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->

            <a class="minibutton danger empty-icon"
               href="/Marneus68/DOSMAN/delete/master/doc/SPEC.md"
               data-method="post" data-test-id="delete-blob-file" rel="nofollow">

          Delete
        </a>
      </div><!-- /.actions -->
    </div>
      
  <div id="readme" class="blob instapaper_body">
    <article class="markdown-body entry-content" itemprop="mainContentOfPage"><p>% Spécifications fonctionnelles - DOSMAN
% Duane Bekaert - Mamadou Coulibali
% 2013-12-18</p>

<h1>
<a name="user-content-dosman" class="anchor" href="#dosman"><span class="octicon octicon-link"></span></a>DOSMAN</h1>

<p>DOSMAN est un front-end graphique <a href="http://www.dosbox.com/">DosBox</a> graphique écrit en C++ utilisant <a href="http://www.gtkmm.org/en/">gtkmm 3.0</a> et ayant pour but d'être utilisé dans des environnements de bureau GNU/.Linux modernes.  </p>

<h2>
<a name="user-content-dosbox" class="anchor" href="#dosbox"><span class="octicon octicon-link"></span></a>DosBox</h2>

<p>DosBox est un émulateur permettant de simuler un environnement MS-DOS et PC-DOS ainsi que le matériel sur lequel ces systèmes fonctionnent. Afin d'obtenir les meilleures performances possibles pour un programme donné, il est souvent nécessaire de spécifier les particularités matérielles du système à émuler, cela comprend la vitesse et le type de processeur, la ram, les différentes cartes son et vidéo, les périphériques à émuler ou ceux à relier à la machine physique (imprimantes, ports série, lecteurs disquette ou CD...) . Ces configurations peuvent être faites dans un fichier "pain text" passé en argument lors de l'invocation de DosBox.</p>

<pre><code>dosbox -conf configuration.conf
</code></pre>

<p>Quand aucun fichier n'est spécifié, c'est la "configuration utilisateur" qui est utilisé. Cette configuration est décrite dans le fichier '~/.dosbox/dosbox-.conf'. Ce fichier est copié depuis un répertoire d'installation lors de la première utilisation de DosBox.  </p>

<h2>
<a name="user-content-mode-de-fonctionnement-propos%C3%A9" class="anchor" href="#mode-de-fonctionnement-propos%C3%A9"><span class="octicon octicon-link"></span></a>Mode de fonctionnement proposé</h2>

<p>DOSMAN devra gérer l'installation, la configuration, l'exécution, la gestion de snapshots, captures d'images et de vidéo de logiciels DOS émulés avec DosBox. Pour ce faire in convient de définir son fonctionnement attendu.  </p>

<p>Chaque logiciel géré par DOSMAN se vera attribué son propre dossier dans le répertoire utilisateur de DOSMAN. Ce répertoire utilisateur sera un répertoire caché propre à DOSMAN désigné à contenir les logiciels gérés dans leurs dossiers respectifs, ainsi que les fichiers de configuration leur étant propre. Le nom proposé pour le répertoire utilisateur de DOSMAN sera <em>~/.dosman/</em> .   </p>

<p>Contenu des répertoires de programmes:   </p>

<ul class="task-list">
<li>Fichier de configuration (dosbox.conf)<br>
</li>
<li>Fichier image servant d'icône dans DOSMAN (cover.jpg, cover.png) [optionnel]<br>
</li>
<li>Sous répertoire contenant les fichiers d'installation du programme<br>
</li>
</ul><p>Plus d'informations sur les fichiers de configuration de dosbox peuvent être trouvés <a href="http://www.dosbox.com/wiki/Dosbox.conf">ici</a>. Ces propriétés sont celles qui devront être éditables dans l'interface de DOSMAN pour chaque programme.  </p>

<h2>
<a name="user-content-biblioth%C3%A8ques-logiciel-utilis%C3%A9es" class="anchor" href="#biblioth%C3%A8ques-logiciel-utilis%C3%A9es"><span class="octicon octicon-link"></span></a>Bibliothèques logiciel utilisées</h2>

<p>Afin de réaliser l'interface graphiue, c'est la bibliothèque <a href="http://www.gtkmm.org/en/">gtkmm 3.0</a> développée par le projet <a href="http://www.gnome.org/">GNOME</a> qui sera utilisée. La lécture et écriture des fichiers de configuration sera effectuée grace à la librairie glibmm, binding C++ de la librairie Glib.</p>

<h2>
<a name="user-content-interface-utilisateur-propos%C3%A9e" class="anchor" href="#interface-utilisateur-propos%C3%A9e"><span class="octicon octicon-link"></span></a>Interface utilisateur proposée</h2>

<p>L'interface utilisateur proposée se divise en plusieurs écrans aussi appelés vues.</p>

<ul class="task-list">
<li>
<p>Vue liste/configuration:
Cette vue est divisée en 3 sections:  </p>

<ul class="task-list">
<li>Barre de tache supérieure permettant l'ajout et la suppression d'entrées de programmes ainsi que l'accès à une fenêtre de configuration de DOSMAN.</li>
<li>Liste des entrées de programmes.</li>
<li>Panneau de configuration permettant la modifications d'éléments du fichier de configuration ainsi que d'ouvrir ce dernier dans un éditeur de texte pour édiion avancée. Le contenu de ce panneau dépends de l'entrée sélectionnée dans la liste des programmes.</li>
</ul>
</li>
<li><p>Vue "Collection"
Cette vue regroupe de façon graphique les différents programmes installés dans DOSMAN en utilisant les images spécifiées dans leur dossiers d'installation. Des icônes par défaut seront utilisés pour les programmes n'ayant pas d'images associées. Cette vue sera proposée par défaut à partir du moment ou au moins un programme sera installé via DOSMAN.   </p></li>
<li><p>Vue configuration:
Cette vue permet de configurer DOSMAN, modifier son dossier utilisateur ou rétablir celui par défaut, sélectionner la page que l'application montrera à son lancement par défaut et d'éditer de fichier de configuration de dosbox global.  </p></li>
</ul><h2>
<a name="user-content-maquettes" class="anchor" href="#maquettes"><span class="octicon octicon-link"></span></a>Maquettes</h2>

<p><a href="/Marneus68/DOSMAN/blob/master/img/gui.png" target="_blank"><img src="/Marneus68/DOSMAN/raw/master/img/gui.png" alt="Proposition d'interface" style="max-width:100%;"></a></p>

<h2>
<a name="user-content-gant" class="anchor" href="#gant"><span class="octicon octicon-link"></span></a>GANT</h2></article>
  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.05837s from github-fe138-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="fullscreen-contents js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-remove-close close js-ajax-error-dismiss"></a>
      Something went wrong with that request. Please try again.
    </div>


      <script crossorigin="anonymous" src="https://assets-cdn.github.com/assets/frameworks-5a921ce2c45d4a5235b8f9c5c716611df0a83a79.js" type="text/javascript"></script>
      <script async="async" crossorigin="anonymous" src="https://assets-cdn.github.com/assets/github-71380a7260f8593a61c90ab35f6f6cf70e28aaba.js" type="text/javascript"></script>
      
      
  </body>
</html>

