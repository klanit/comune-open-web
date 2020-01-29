CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Data processing configuration -tab

INTRODUCTION
------------
GDPR consent is a module that aims to help services to become more
GDPR compliant. This is achieved within this module by producing acceptable
consents to end users.

Module can be configured to suit different levels of enforcements even down
to not enforcing but only recommending to consent.

REQUIREMENTS
------------
There are no special requirements for the module or dependencies. It's built to
be stand alone solution. However to get most out of it you should have views
installed as it provides display to module configuration page that helps
you to see accepted consents and provides audit trail as users might have
revoked their consent permanently or temporarily.

In addition you can have locale installed and module will support different
languages by providing different consent depending what language user has
selected in their profile.

INSTALLATION
------------
Install as usual. See. https://www.drupal.org/docs/7/extend/installing-modules

CONFIGURATION
-------------
Go to http(s)://<yoursite/admin/config/people/gdpr_consent for configuration.

Create first version of your consent. If you have multiple languages defined
it will create the same consent for every language. You can update these by
switching languages via switcher links.

You can also provide data details of what data you gather and other information.
HTML tags are allowed as per your text filter configuration.

You can select different display methods for consent (page and user profile
page).
- Scroll box: Limits the height of the box and provides scroll.
- HTML text (default): You can use HTML text.
- Link: Provides link to consent page (via profile).

From language tab you can select if you want to create new version for all
languages or update specific revision only. You can also select who should
accept your updated consent.

If you want to explain changes you have done to make it easier for end users
to see what has changed you're able to do so by providing info via explain
changes tab.

DATA PROCESSING CONFIGURATION -TAB
----------------------------------
Here you will find some options how module should behave:

Ask to accept at login
If only this is selected (you don't enforce consent) users are prompted to
accept consent at the beginning of their session. They can bypass consent at
will and continue using the site as they see fit. This is not recommended
normally for compliance but you can do it.

Force to have accepted consent
Users are not allowed to continue using service if they don't accept the
consent. This enforces very strong compliance for logged in users especially
if you combine it with option "Prevent users from accessing admin pages without
consent".

Prevent users from accessing admin pages without consent
Self explanatory. Doesn't allow admin pages to be accessed without consent.
However module configuration page is an exception to the rule as you could
otherwise lock yourself up (albeit you could just give consent).

Nag message
Provide nag message to be shown as drupal message for users who try to navigate
without consent if consent is forced.

Exempt user roles
What roles are exempt from consent acquisition.
