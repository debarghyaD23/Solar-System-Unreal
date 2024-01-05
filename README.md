# Simplified model of Solar system
In this project we create a simplified model of solar system in Unreal Engine 5. That is, we create planets revolving around sun. 
## Requirements
 - Create the sun and the nine planets with different color or texture on a dark background
 - Each planet should be revolving around the Sun at different velocities, their relative velocities should remain realistic. The scale of velocity should be controllable from a config file[.ini file].
 - The planets rotate around their own axes
 - The planet’s trajectory should be visible by a **procedural mesh component**
 - The view should be moveable around the sun by dragging left mouse button; dragging the mouse horizontally should rotate the view around the sun horizontally, dragging it vertically should rotate the view vertically
 - If a planet is clicked on a UI panel shows its mass, velocity, diameter and current distance from sun. The current distance should update as they rotate, because most of them shall have elliptic trajectory. Right-clicking should cancel the panel
### Technical requirements
 - Create a Gitlab user and let the coordinator know the username/email. You shall be granted access to [session01](https://gitlab.com/zt-in-k/academyassignments/session01) repository as developers. We'll also create branches for you to work on.
 - Create SSH keypair and add public key to gitlab as described here https://docs.gitlab.com/ee/user/ssh.html#add-an-ssh-key-to-your-gitlab-account
 - Under [session01](https://gitlab.com/zt-in-k/academyassignments/session01) repository create a branch with the convention `<yourname>-mr`
 - Create a merge request with `<yourname>-mr` branch to `<yourname>` branch which is already created. The MR name should be **\[\<yourname\>-solar-system\]**
 - Clone the branch locally with `git clone git@gitlab.com:zt-in-k/academyassignments/session01.git -b <yourname>-mr` and commit your changes there with `git commit`, upload the same with `git push`
 - The project should use primarily C++ with none to minimal Blueprint for logic.
### Time limit
 - The project should be completed within 4 weeks
## Hints
 - Install Visual Studio 2022 Community edition https://visualstudio.microsoft.com/vs/community/. If it is alsready installed, use that one
 - Install Unreal Engine 5 https://docs.unrealengine.com/5.0/en-US/installing-unreal-engine/. If this or any other version of UE is installed, use that one
 - Create blank C++ project **without starter content**
 - Use sphere static mesh engine asset to create planets and sun, give it a scale to make different sizes
 - Create different material instances for each planet with different colors
 - Use UMG to create the planet details UI, show or hide on mouse click
 - Unreal C++ https://unrealcpp.com/(Tutorials are for Unreal Engine 4 but codes are still valid for UE 5)
 - Unreal Engine UI tutorials https://benui.ca/ 
