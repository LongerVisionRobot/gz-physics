/*
 * Copyright (C) 2022 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef GZ_PHYSICS_BULLET_FEATHERSTONE_SRC_SDFFEATURES_HH_
#define GZ_PHYSICS_BULLET_FEATHERSTONE_SRC_SDFFEATURES_HH_

#include <string>

#include <gz/physics/sdf/ConstructCollision.hh>
#include <gz/physics/sdf/ConstructModel.hh>
#include <gz/physics/sdf/ConstructWorld.hh>
#include <gz/physics/Implements.hh>

#include <sdf/Collision.hh>

#include "EntityManagementFeatures.hh"

namespace gz {
namespace physics {
namespace bullet_featherstone {

struct SDFFeatureList : gz::physics::FeatureList<
  sdf::ConstructSdfModel,
  sdf::ConstructSdfWorld,
  sdf::ConstructSdfCollision
> { };

class SDFFeatures :
    public virtual EntityManagementFeatures,
    public virtual Implements3d<SDFFeatureList>
{
  public: Identity ConstructSdfWorld(
      const Identity &/*_engine*/,
      const ::sdf::World &_sdfWorld) override;

  public: Identity ConstructSdfModel(
      const Identity &_worldID,
      const ::sdf::Model &_sdfModel) override;

  public: bool AddSdfCollision(
      const Identity &_linkID,
      const ::sdf::Collision &_collision,
      bool isStatic);

  private: Identity ConstructSdfCollision(
      const Identity &_linkID,
      const ::sdf::Collision &_collision) override;
};

}  // namespace bullet_featherstone
}  // namespace physics
}  // namespace gz

#endif
